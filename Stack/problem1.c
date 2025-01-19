#include <stdio.h>
#include <stdlib.h>

#define maxsize 100

typedef struct stack {
    int data[maxsize];
    int top;
    int size;
}stack;


void initialize (stack *s) {
    s->top = -1;
    s->size = 0;
}


void clearStack(stack *s) {
    s->top = -1;
    s->size = 0;
}

void stackSize(stack *s){
    printf("The current size of the stack is %d\n", s->size);
}

void push(stack *s, int value) {
    if (s->top == maxsize - 1) {
        printf("Stack is full\n");
    }
    else {
        s->data[++s->top] = value;
        s->size++;
    }
}

void pop(stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    }
    else{
       s->top--;
       s->size--;

    }
}

void transferOdd(stack *s1, stack *s2) {
    int i;
    stack temp;
    initialize(&temp);


    for (i = 0; i <= s1->top; i++) {
        if (s1->data[i] % 2 != 0) {
            push(s2, s1->data[i]);
        }
        else{
            push(&temp, s1->data[i]);

        }
    }
    clearStack(s1);
    for (i = 0; i <= temp.top; i++) {
        push(s1, temp.data[i]);
    }

}




void printStack(stack s) {
    int i;
    for (i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
        }
        printf("\n");
}

//Example implementation.
int main(){
    stack s1;
    initialize(&s1);
    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);
    push(&s1, 6);
    push(&s1, 7);
    push(&s1, 8);
    
    
    stack s2;
    initialize(&s2);

    transferOdd(&s1, &s2);
    stackSize(&s1);
    printf("Stack 1: ");
    printStack(s1);
    stackSize(&s2);
    printf("Stack 2: ");
    printStack(s2);
}



