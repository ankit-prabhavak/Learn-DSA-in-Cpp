#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


struct Stack {
    int top;
    char arr[MAX];
};


void initStack(struct Stack *s) {
    s->top = -1;
}


int isEmpty(struct Stack *s) {
    return s->top == -1;
}


void push(struct Stack *s, char ch) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = ch;
    }
}


char pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1;
}


int isBalanced(char *expression) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

       
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        }
       
        else if (ch == ')' || ch == ']' || ch == '}') {
          
            if (isEmpty(&s)) {
                return 0; 
            }
            char top = pop(&s);
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return 0; 
            }
        }
    }

    
    return isEmpty(&s);
}

int main() {
    char expression[MAX];
    
    printf("Enter a string of parentheses: ");
    fgets(expression, MAX, stdin);

    
    expression[strcspn(expression, "\n")] = '\0';

    if (isBalanced(expression)) {
        printf("The parentheses are balanced!\n");
    } else {
        printf("The parentheses are not balanced!\n");
    }

    return 0;
}
