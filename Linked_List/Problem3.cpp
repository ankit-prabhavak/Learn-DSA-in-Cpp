//Given the head of a singly linked list, print the reverse list.

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

void reversePrint(Node* address){
    if(address == NULL)
    return;

    reversePrint(address->next);
    cout << address->value << " ";   
}



int main(){


    LinkedList ll;

    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(20);
    ll.insertAtEnd(40);
    ll.insertAtEnd(40);
    ll.insertAtEnd(40);

    ll.display();
    reversePrint(ll.head);
    



    return 0;
}