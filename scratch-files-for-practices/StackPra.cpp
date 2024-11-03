#include <iostream>
using namespace std;
#define MAX 5

struct Stack
{
    int stack[MAX];
    int top = -1;

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Can't push. Stackoverflow" << endl;
        }
        else {
            stack[++top] = value;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Can't pop. Stackunderflow" << endl;
        }
        else {
            cout << "Pop: " << stack[top] << endl;
            top--;
        }
    }

    void displayStack() {
        if (top == -1) {
            cout << "Can't display. Stackunderflow" << endl;
        }
        else {
            cout << "Stack elements: "<< endl;
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << ' ';
            }
        cout << endl;
        }
    }

};

int main() {
    Stack stk;
    stk.push(5);
    stk.push(6);
    stk.displayStack();
    stk.pop();
    stk.displayStack();

    return 0;
}
