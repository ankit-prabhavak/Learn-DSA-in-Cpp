#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int p;
    struct node *next;

}Node;

Node* createNode(int value, int priority){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->p = priority;
    newNode->next = NULL;

    return newNode;
}


void insertPriorityQueue(Node** head, Node** tail, int value, int priority){
    Node* newNode = createNode(value, priority);

    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
        return;

    }

    if((*head)->p <= priority){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    if((*tail)->p > priority){
        (*tail)->next = newNode;
        *tail = newNode;
        return;
    }

    Node * temp = *head;

    while(temp->next->p > priority && temp->next != NULL){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return;



}

void printQueue(Node *head){

    if(head == NULL){
        printf("Nothing to print.");
        return;
    }

    Node *temp = head;

    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
    return;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;


    insertPriorityQueue(&head,&tail,10,2);
    insertPriorityQueue(&head,&tail,20,1);
    insertPriorityQueue(&head,&tail,30,3);
    insertPriorityQueue(&head,&tail,96,4);
    insertPriorityQueue(&head,&tail,78,6);
    insertPriorityQueue(&head,&tail,52,5);

    printQueue(head);

    return 0;

}