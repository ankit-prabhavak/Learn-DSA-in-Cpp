#include <stdio.h>
#include <stdlib.h>

// Define the doubly linked list node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node** head, int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;  // Handle memory allocation failure
    }

    // Initialize the new node
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If the list is empty, the new node becomes the head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Traverse to the last node
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Insert the new node at the end
        temp->next = newNode;
        newNode->prev = temp;
    }

    return *head;  // Return the head of the modified list
}

// Function to merge two sorted doubly linked lists
struct Node* mergeTwoDdll(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;

    // Merge the two lists
    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            result = insertAtEnd(&result, l1->data);
            l1 = l1->next;
        } else {
            result = insertAtEnd(&result, l2->data);
            l2 = l2->next;
        }
    }

    // Add remaining nodes from l1 if any
    while (l1 != NULL) {
        result = insertAtEnd(&result, l1->data);
        l1 = l1->next;
    }

    // Add remaining nodes from l2 if any
    while (l2 != NULL) {
        result = insertAtEnd(&result, l2->data);
        l2 = l2->next;
    }

    return result;  // Return the merged list
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to create a new node with the given data and insert it at the end of the list
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Main function to test the mergeTwoDdll function
int main() {
    // Creating two sorted doubly linked lists

    struct Node* l1 = NULL;
    l1 = insertAtEnd(&l1, 1);
    l1 = insertAtEnd(&l1, 3);
    l1 = insertAtEnd(&l1, 5);

    struct Node* l2 = NULL;
    l2 = insertAtEnd(&l2, 2);
    l2 = insertAtEnd(&l2, 4);
    l2 = insertAtEnd(&l2, 6);

    // Merging the two sorted lists
    struct Node* mergedList = mergeTwoDdll(l1, l2);

    // Print the merged list
    printf("Merged Sorted Doubly Linked List: ");
    printList(mergedList);

    return 0;
}
