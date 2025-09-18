#include <iostream>

using namespace std;


class Node {
public:
      int data;
      Node* next;

      Node(int val) {
        data = val;
        next = NULL;
    
      }
};

class List {
    Node* head;
    Node* tail;

public:
      List() {
        head = tail = NULL;
      }

      void push_front(int val) {
        Node* newNode = new Node(val); // Dynamic
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }

      }

      void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }

      }

      void pop_front(){
        if(head == NULL){
            cout << "Linked List is empty" << endl;
            return;
        }
        Node* temp = head;
        head  = head->next;
        temp->next = NULL;

        delete temp;

      }

      void pop_back(){
        if(head == NULL){
            cout << "Linked List is empty" <<endl;
            return;
        }
        Node* temp = head;
        while(temp->next != tail) temp = temp->next;

        temp->next = NULL;
        delete tail;
        tail = temp;

      }

      void insert(int val, int pos){
        if(pos < 0){
            cout << "Invalid position" << endl;
            return;
        }

        if(pos == 0){
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i = 0; i < pos-1; i++) {
            if(temp == NULL) {
                cout << "Invalid position" << endl;
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

      }

      int search(int key) {
        if(head == NULL){
            cout << "Linked List is empty" <<endl;
            return -1;
        }

        Node* temp = head;
        int idx = 0;

        while(temp != NULL) {
            if(temp->data == key){
                return idx;
            }

            temp = temp->next;
            idx++;
        }

        return -1;
      }

      void insertionSortLL() {
            if (!head || !head->next) return;

            Node* sorted = nullptr; // New sorted list

            Node* curr = head;
            while (curr) {
                Node* next = curr->next;

                // Insert curr into sorted list
                if (!sorted || curr->data < sorted->data) {
                    curr->next = sorted;
                    sorted = curr;
                } else {
                    Node* temp = sorted;
                    while (temp->next && temp->next->data < curr->data) {
                        temp = temp->next;
                    }
                    curr->next = temp->next;
                    temp->next = curr;
                }
                curr = next;
            }
            head = sorted;
            // Update tail
            tail = head;
            while (tail && tail->next) tail = tail->next;

          }
           
      void printLL() {
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;   
      }

};



// Testing function
int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(56);

    ll.printLL();
    ll.pop_front();
    ll.printLL();
  
    ll.pop_back();
    ll.insert(56,2); // 0 based indexing
    ll.printLL();

    cout << ll.search(3) << endl;
    ll.insertionSortLL();

    ll.printLL();


    return 0;
}