#include <iostream>
using namespace std;

#define MAX 5 // maximum elements in the stack

struct Stack
{
    int stack[MAX];
    int top = -1;  // must initialize as global or in main()

    void push(int element) {
        if (top == MAX - 1) {
            cout << "Stack overflow" << endl;
        }
        else {
            stack[++top] = element;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
        }
        else {
            cout << "popped item: " << stack[top--] << endl;
        }
    }

    void displayStack() {
        if (top == -1) {
            cout << "Can't display. Stack underflow (empty)" << endl;
        }
        else {
            cout << "Items in stack: " << endl;
            for (int i = top; i >= 0; i--)  // first-in-last-out print
            {
                cout << stack[i] << endl;
            }
            
        }
    }
};

int main() {
    Stack stk;
    
    stk.displayStack();
    stk.pop();

    stk.push(5);
    stk.push(12);
    stk.push(9);
    stk.push(7);

    stk.displayStack();
    stk.pop();
    stk.displayStack();

    return 0;
}