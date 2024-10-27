#include <iostream>
using namespace std;

class Stack{
    private:
        int* stack;
        int top;
        int capacity;
    public:
        // C++ constructor no-parameters
        Stack() {
            capacity = 5;  // default capacity            
            stack = new int[capacity];
            top = -1;
        }

        // C++ constructor with parameter
        Stack(int size) {
            stack = new int[size];
            top = -1;
            capacity = size;
        }

        //~Stack() {
        //     delete[] stack;
        //     cout << "Stack is deleted. memory is freed" << endl;
        // }

        void push(int value) {
            if (top == capacity -1) {
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
            if (top == -1)
            {
                cout << "Stack is empty" << endl;
            }
            else {
                cout << "Stack values are: ";

                for (int i = 0; i < top + 1; i++) {
                    cout << stack[i] << ' ';
                }
                cout << endl;
            }
        }
};

int main() 
{
    Stack stk;
    Stack stk2(3);
    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.push(8);
    stk.push(9);

    stk.display();
    stk.pop();
    stk.display();

    stk2.display();

    stk2.push(1);
    stk2.push(2);
    stk2.push(3);
    stk2.push(4);


    stk2.display();
    stk2.pop();
    stk2.display();

    return 0;
}