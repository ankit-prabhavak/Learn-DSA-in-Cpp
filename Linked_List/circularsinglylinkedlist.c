#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next; //Stores the address of the next node.

}Node;


Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = newNode;
    return newNode;

} 


void insertAtEnd(Node **head, int value){
    Node *newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }

   
    Node *temp = *head;

    while( temp->next != *head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;

}

void insertAtbeg(Node **head, int value){
    Node *newNode = createNode(value);

    Node *current = *head;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    while(current->next != *head){
        current = current->next;
    }
    current->next = newNode;
    newNode->next = *head;
    *head = newNode;
    
}



void printList(Node *head){
    Node *current = head;

    if( head == NULL){
        printf("List is empty!\n");
        return;
    }
   
    do{

      printf("%d -> ",current->data);
      current = current->next;

    }while(current != head);

    printf("head\n");

}


int main(){
    Node* head = NULL;

    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    insertAtEnd(&head,40);

    printf("The circular linked list is: ");
    printList(head);

    Node* l = NULL;
    insertAtbeg(&l, 1);
    insertAtbeg(&l, 2);
    insertAtbeg(&l, 3);
    insertAtbeg(&l, 0);
    printf("The circular linked list is: ");
    printList(l);


    return 0;
}