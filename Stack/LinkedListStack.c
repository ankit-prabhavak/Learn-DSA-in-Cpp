#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1); // exit if memory allocation fails
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void initializeStack(Stack** stack) {
    *stack = (Stack*)malloc(sizeof(Stack));
    if (*stack == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    (*stack)->top = NULL;
    (*stack)->size = 0;
}

void pushValue(Stack** stack, int value) {
    Node* newNode = createNode(value);
    if ((*stack)->top == NULL) {
        (*stack)->top = newNode;
    } else {
        newNode->next = (*stack)->top;
        (*stack)->top = newNode;
    }
    (*stack)->size += 1;
}

void popValue(Stack** stack) {
    if ((*stack)->top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    Node* temp = (*stack)->top;
    int value = (*stack)->top->data;
    (*stack)->top = (*stack)->top->next;
    free(temp);

    (*stack)->size -= 1;
    printf("%d has been popped out.\n", value);
}

void printStack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty. Nothing to print.\n");
        return;
    }

    Node* temp = stack->top;
    printf("The Stack is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printStackSize(Stack* stack) {
    printf("The size of the stack is: %d\n", stack->size);
}

// Function to clear the stack (free all nodes)
void clearStack(Stack* stack) {
    Node* temp;
    while (stack->top != NULL) {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);  // Free the current node
    }
    stack->size = 0;  // Reset stack size
    printf("Stack has been cleared.\n");
}

int main() {
    Stack* stack = NULL;
    initializeStack(&stack);

    pushValue(&stack, 10);
    pushValue(&stack, 20);
    pushValue(&stack, 30);

    printStack(stack);

    popValue(&stack);
    printStack(stack);

    printStackSize(stack);

    clearStack(stack);  // Clear the stack
    printStack(stack);
    printStackSize(stack);

    return 0;
}
