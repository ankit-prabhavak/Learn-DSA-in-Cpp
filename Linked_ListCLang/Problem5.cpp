//Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified  list.
#include <iostream>

using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node(int data){
        value = data;
        next = nullptr;

    }
};

class  LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = nullptr;
        }

        void insertAtEnd(int value){
            Node* newNode = new Node(value);
            if(head == NULL){
                head = newNode;
                return;
            }

            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
                }

                temp->next = newNode;
        }

        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->value << " ";
                temp = temp->next;
                }
                cout<<endl;
        }

};

Node* reverseLL(Node* &head, int k){
    Node* prev = nullptr;
    Node* current = head;
    Node* after = nullptr;

    int count = 0;//for counting first k nodes
    while(current != nullptr && count < k){
        after = current->next;
        current->next = prev;
        prev = current;
        current = after;
        count++;
    }
    //current pointer will  be at the end of first k nodes
    if(current != NULL){
    Node* newHead = reverseLL(current, k);
    head->next = newHead;
    }

    return prev; //prev pointer will give the new head of the connected linked list.

}





int main(){


    LinkedList ll;

    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.insertAtEnd(50);
    ll.insertAtEnd(60);

    ll.display();
    ll.head = reverseLL(ll.head, 2);
    ll.display();



    return 0;
}


