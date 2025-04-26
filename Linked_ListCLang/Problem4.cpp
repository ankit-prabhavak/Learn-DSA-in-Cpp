


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

//without recursion.
void reversedLL(Node* &head){
    Node* prev = nullptr;
    Node* current = head;
    Node* after = nullptr;

    while(current != NULL){
        after = current->next;
        current->next = prev;
        prev = current;
        current = after;
    }
    //when loop ends.
    head = prev;
}

//using recursion.
Node*  reverseLinkedList(Node* &head){
    //base case.
    if(head == NULL || head->next == NULL){
        return head;
    }

    //recursive case
    Node* newHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return  newHead;
}





int main(){


    LinkedList ll;

    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(20);
    ll.insertAtEnd(40);
    ll.insertAtEnd(40);
    ll.insertAtEnd(40);
    
    cout<<"before reversing: ";
    ll.display();
    cout<<"after reversing: ";
    reversedLL(ll.head);
    ll.display();
    cout<<"after reversing again: ";
    ll.head = reverseLinkedList(ll.head);
    ll.display();
   
    return 0;
}