// Given the head of the linked list, delete every alternate element from the list starting from the second  element.

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



void deleteAlternateNode(Node* &head){
    Node* current = head;

    while(current != NULL &&  current->next != NULL){
        Node* temp = current->next; //this is the node to be deleted.
        current->next = current->next->next; //this is the node after the node to  be deleted.
        free(temp);
        current = current->next;

    }
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
    
    deleteAlternateNode(ll.head);
    ll.display();



    return 0;
}

