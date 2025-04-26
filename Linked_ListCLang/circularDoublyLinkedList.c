#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a doubly circular linked list
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
    newNode->next = newNode;  // Points to itself for circularity
    newNode->prev = newNode;  // Points to itself for circularity
    return newNode;
}

// Function to insert a node at the head of the doubly circular linked list
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;  // When the list is empty, new node is the only node
    } else {
        struct Node* tail = (*head)->prev;
        
        // Adjust the next and prev pointers to maintain circular structure
        newNode->next = *head;
        newNode->prev = tail;
        
        // Update the head's prev pointer and the tail's next pointer
        (*head)->prev = newNode;
        tail->next = newNode;
        
        // Move the head pointer to the new node
        *head = newNode;
    }
}

// Function to insert a node at the tail of the doubly circular linked list
void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;  // When the list is empty, new node is the only node
    } else {
        struct Node* tail = (*head)->prev;
        
        // Adjust the next and prev pointers to maintain circular structure
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
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
    
    prevNode->next->prev = newNode;
    prevNode->next = newNode;
}


void delete(struct Node** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
        }


        if (*head == (*head)->next) {
        free(*head);  // Free the only node
        *head = NULL;  // Set the head to NULL as the list is now empty
        return;
    }
        struct Node* temp = *head;
        struct Node* tail = (*head)->prev;

        *head = (*head)->next;
        (*head)->prev = tail;
        tail->next = *head;
        free(temp);
        

}


// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = *head;
    do {
        if (temp->data == key) {
            if (temp == *head && temp->next == *head) {
                free(temp);
                *head = NULL;  // If there's only one node
                return;
            }
            
            // Adjust pointers to delete the node
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            
            // If we are deleting the head node, move the head to the next node
            if (*head == temp) {
                *head = temp->next;
            }
            
            free(temp);
            return;
        }
        temp = temp->next;
    } while (temp != *head);  // Loop until we complete the circular traversal
    
    printf("Node with value %d not found\n", key);
}

// Function to print the list from head to tail (circular traversal)
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Stop when we come back to the head
    printf("\n");
}

// Function to print the list from tail to head (circular backward traversal)
void printListBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* tail = head->prev;
    struct Node* temp = tail;
    printf("Circular List (Backward): ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != tail);  // Stop when we complete a full circular traversal
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements at the head and tail
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtTail(&head, 5);
    insertAtTail(&head, 1);
   // delete(&head);
    // Print the list in circular fashion (forward)
    printList(head);

    // // Print the list in reverse circular fashion (backward)
    // printListBackward(head);

    // // Insert after a node (insert after the node with value 10)
    // struct Node* temp = head;
    // while (temp != NULL && temp->data != 10) {
    //     temp = temp->next;
    // }
    // insertAfter(temp, 15);

    // // Print the updated list
    // printList(head);
    // printListBackward(head);

    // // Delete a node by value
    // deleteNode(&head, 10);  // Deleting node with value 10
    // deleteNode(&head, 100);  // Node not found

    // // Print the final list
    // printList(head);
    // printListBackward(head);

    return 0;
}
