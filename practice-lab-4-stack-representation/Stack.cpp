#include <iostream>
using namespace std;
#define Size 5

int stack[Size];
int top = -1;

void push(int value) {
    if (top == Size -1) {
        cout << "Stack overflow" << endl;
    }
    else {
        top++;
        stack[top] = value;
    }
}

void printStack() {
    cout << "stack values: ";
    for (size_t i = 0; i <= top ; i++)
    {
        cout << stack[i] << ' ';
    }
    cout << endl;
}

int pop() {
    if (top == -1)
    {
        cout << "Stack underflow";
        return 1;
    }
    else 
    {
        return stack[top--];  // decrements top after returning the value
    }
}

int main() {
    push(4);
    push(4);
    push(4);
    push(4);
    push(6);
    push(4);

    printStack();
    cout << "Pop:" << pop() << endl;
    printStack();

    return 0;
}