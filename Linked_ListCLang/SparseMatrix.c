#include <stdio.h>
#include <stdlib.h>


// Node structure for the linked list
struct Node {
    int row, col, value;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to convert matrix to linked list
struct Node* linkedListRepresentation(int sparseMatrix[3][3]) {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sparseMatrix[i][j] != 0) {
                struct Node* newNode = createNode(i, j, sparseMatrix[i][j]);
                if (head == NULL) {
                    head = newNode;
                } else {
                    temp->next = newNode;
                }
                temp = newNode;
            }
        }
    }

    return head;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    printf("Linked List Representation:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Row: %d, Col: %d, Value: %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    int sparseMatrix[3][3] = {
        {0, 0, 3},
        {0, 4, 0},
        {5, 0, 0}
    };

    struct Node* head = linkedListRepresentation(sparseMatrix);
    printLinkedList(head);
    
    return 0;
}



