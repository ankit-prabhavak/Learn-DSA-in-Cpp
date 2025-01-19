#include <iostream>

using namespace std;

#define maxSize 100
int stack[maxSize];
int top = -1;

//function to perform push operation on the stack.
void push(int data)
{
    if(top >= maxSize - 1){
    cout << "Stack Overflow\n";
    return;
    }
    cout<<data<<" pushed to stack\n"<<endl;
    stack[++top] = data;
}

//function to perform pop operation on the stack.
int pop(){
    if(top < 0){
        cout <<"Stack Underflow\n"<<endl;
        return -1;
    }
    int data = stack[top--];
    cout<<data<<" popped from stack\n"<<endl;
    return data;

}

void printStack(){
    cout<<"The stack is: ";
    for(int i = top; i >= 0; i--){
        cout<<stack[i]<<" ";
        }
    cout<<endl;

    return;

}

int main(){
    push(5);
    push(10);
    push(15);
    printStack();

    pop();
    printStack();




    return 0;
}