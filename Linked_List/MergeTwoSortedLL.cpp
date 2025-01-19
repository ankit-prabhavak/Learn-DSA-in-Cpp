//Write a function that take the head of the two sorted linked list and merge them into a single sorted linked list.

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


LinkedList mergeTwoLinkedlist(Node* head1,  Node* head2){
    LinkedList list;
    Node* temp = head1;
    Node*  temp2 = head2;
    while(temp != NULL && temp2 != NULL){
        if(temp->value < temp2->value){
            list.insertAtEnd(temp->value);
            temp = temp->next;
        }
        else{
            list.insertAtEnd(temp2->value);
            temp2 = temp2->next;
        }
    }

    while(temp  != NULL){
          list.insertAtEnd(temp->value);
          temp = temp->next;
    }

    while(temp2  != NULL){
        list.insertAtEnd(temp2->value);
        temp2 = temp2->next;
        }

    return  list;

}

void deleteAtposition(Node* &head,  int data){
    Node*  temp = NULL;
    //check if  the head is the node to be deleted
    if(head == NULL){
      
        return;
        }

        else if(head->value ==  data){
            temp = head;
            head = head->next;
            delete temp;
        }

        else{
            Node* current =  head;
        while(current->next->value  != data){
            current = current->next;
        }
        temp  = current->next;
        current->next = temp->next;
        delete  temp;

        }
}




int main(){
    LinkedList l1;
    l1.insertAtEnd(10);
    l1.insertAtEnd(20);
    l1.insertAtEnd(30);

    LinkedList  l2;
    l2.insertAtEnd(4);
    l2.insertAtEnd(5);
    l2.insertAtEnd(6);
    
    cout<<"Linked List  1: ";
    l1.display();

    cout<<"Linked list  2: ";
    l2.display();

    

    LinkedList l3 = mergeTwoLinkedlist(l1.head, l2.head);
    cout<<"The  Merged Linked List is: ";
    l3.display();
    



    return 0;
}