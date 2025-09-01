#include <iostream>


using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};


class Queue {
    Node* tail;
    Node* head;
   
    public:
    Queue() : head(nullptr), tail(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (!head){
            throw runtime_error("Queue is empty");
            return;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr; // If the queue is empty after pop
    }

    int front() {
        if (!head) throw runtime_error("Queue is empty");
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }

};



int main(){

    Queue q;
    q.push(10);
    q.push(20);
    cout << q.front() << endl; // Outputs: 10
    q.pop();
    cout << q.front() << endl; // Outputs: 20
    q.pop();
    cout << q.isEmpty() << endl; // Outputs: 1 (true)


    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    while(!q.isEmpty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}