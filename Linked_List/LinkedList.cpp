#include <iostream>

using namespace std;

class Node{
   public:
   int val;
   Node * next ;

   Node(int data){
     val = data;
     next = NULL;
   }


};

void insertAtBeg(Node * &head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*  &head, int val){
    Node* newNode = new Node(val);
    Node* last = head;
    if(head == NULL){
        head = newNode;
        }
    
    while(last->next!=NULL){
        last = last->next;
    }
    //we have reached the end of the list
    last->next = newNode;
    }


void insertAtPosition(Node*  &head, int val, int pos){
    Node* newNode = new Node(val);
    if(pos == 0){
        insertAtBeg(head, val);
        }
        else{
            Node* temp = head;
            int current = 0;
            while(current !=  pos-1){
                temp = temp->next;
                current++;
                }
                newNode->next = temp->next;
                temp->next = newNode;
        }

}

void updateAtPosition(Node*   &head, int val, int pos){
    Node* temp = head;
    int current = 0;
    while(current !=  pos-1){
        temp = temp->next;
        current++;
        }
    //we have reached at the required  position

        temp->val = val;
}

void  deleteAtBeg(Node*  &head){
    Node* temp = head; // store the head node

    head = head->next;
    free(temp);
}

void deleteAtEnd(Node*   &head){
    Node* secondLastNode  = head;

    while(secondLastNode->next->next != NULL){
        secondLastNode = secondLastNode->next;
    }
    // Now we have  reached the second last node
    Node* temp  = secondLastNode->next;
    secondLastNode->next = NULL;
    free(temp);
    
}

void deleteAtPosition(Node*    &head, int pos){
    Node* previous = head;
    int current = 0;
    if(pos == 0){
        deleteAtBeg(head);
        return ; 
    }
    
    while(current !=  pos-1){
        previous = previous->next;
        current++;
        }
    
    //we have reached at the required  position
    Node* temp = previous->next;
    previous->next = previous->next->next;
    free(temp);

}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
        }
        cout << endl;
        
}


void sortLinkedList(Node* &head){
    Node* current = head;
    Node* index = NULL;
    if(head == NULL){
        cout<<"Linked list is empty."<<endl;
        return;
    }
    else{
        while(current != NULL){
            index = current->next;
            while(index != NULL){
                if(current->val > index->val){
                    int temp = current->val;
                    current->val = index->val;
                    index->val = temp;
                }
                index = index->next; 
            }
            current = current->next;
        }
    }

}

void searchLinkedlist(Node* head, int data){
    Node* current = head;
    if(current == NULL){
        cout<<"Node does not exist."<<endl;
        
    }
    else{
        while(current != NULL){
            if(current->val == data){
                cout<<"Element is present at Node: "<<current<<endl;
                return;
            }
            current = current->next;
        }
        cout<<"Element is not present in the linked list."<<endl;
        return;
    }


}

//Implementation  of the above functions
int main(){

    Node* head = NULL;
    insertAtBeg(head, 10);
    insertAtBeg(head, 20);
    insertAtBeg(head, 30);
    insertAtEnd(head,78);
    insertAtPosition(head, 10, 2);
    updateAtPosition(head, 18, 4);
    deleteAtBeg(head);
    deleteAtEnd(head);
    deleteAtPosition(head, 2);
    display(head);
    searchLinkedlist(head,40);
    sortLinkedList(head);
    display(head);


    return 0;
}