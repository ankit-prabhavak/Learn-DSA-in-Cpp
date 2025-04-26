//Given the head of a sorted linked list , delete all duplicates such that each element appears only once. Return the linked list sorted as well.

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

void deleteDuplicateNode(Node* &head){
    Node*  current = head;
       while(current != NULL){

        //loops  through the linked list to find the next node with the same value
        while( current->next && current->value ==  current->next->value){
            Node* temp =  current->next;
            current->next = temp->next;
            free(temp);
        }
        current = current->next;
    }

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
    deleteDuplicateNode(ll.head);
    ll.display();



    return 0;
}


