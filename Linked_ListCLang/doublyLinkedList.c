#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the doubly linked list
void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to insert a node after a given node
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    
    prevNode->next = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    // If the list is empty
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    // Search for the node to delete
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL) {
        printf("Node with value %d not found\n", key);
        return;
    }

    // If the node is the head node
    if (*head == temp) {
        *head = temp->next;
    }

    // If the node to delete is not the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // If the node to delete is not the first node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Function to print the list from head to tail
void printListForward(struct Node* head) {
    struct Node* temp = head;
    printf("Forward List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




// Function to print the list from tail to head
void printListBackward(struct Node* head) {
    struct Node* temp = head;
    // Traverse to the last node
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Backward List: ");
    // Traverse backward from the last node
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements at the head and tail
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtTail(&head, 5);
    insertAtTail(&head, 1);

    // Print list from head to tail
    printListForward(head);

    // Print list from tail to head
    printListBackward(head);

    // Insert after a node (inserting after the second node which contains 10)
    struct Node* temp = head;
    while (temp != NULL && temp->data != 10) {
        temp = temp->next;
    }
    insertAfter(temp, 15);

    // Print the updated list
    printListForward(head);
    printListBackward(head);

    // Delete a node by value
    deleteNode(&head, 10);
    deleteNode(&head, 100); // Node not found

    // Print the final list
    printListForward(head);
    printListBackward(head);

    return 0;
}


