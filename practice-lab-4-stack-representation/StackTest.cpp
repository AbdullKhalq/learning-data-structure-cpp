#include <iostream>
using namespace std;

class StackTest
{
private:
    int* stack;
    int top;
    int capacity;
public:
    StackTest() {
        capacity = 5;
        stack = new int[capacity];
        top = -1;
    }

    StackTest(int size) {
        capacity = size;
        stack = new int[capacity];
        top = -1;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack overflow" << endl;
        }
        else {
            stack[++top] = value;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return 0;
        }
        else {
            return stack[top--];
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << "Stack values are: ";
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << ' ';
            }
            cout << endl;
        }
    }

};

int main () {
    StackTest stk;
    StackTest stk2(2);

    stk.pop();
    stk.push(4);
    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.push(8);
    stk.push(9);
    stk.display();
    cout << "pop: " << stk.pop() << endl;
    stk.display();

    stk2.pop();
    stk2.push(1);
    stk2.push(2);
    stk2.push(3);
    stk2.display();
    stk2.pop();
    stk2.display();

    return 0;
}