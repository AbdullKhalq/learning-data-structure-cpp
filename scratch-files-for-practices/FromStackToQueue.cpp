#include <iostream>
using namespace std;
#define MAX 5

struct Queue
{
    int queue[MAX];
    int front = -1;
    int rear = -1;

    // Adds an element to the rear of the queue
    void enqueue(int element) {

        // when queue is empty
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
            queue[rear] = element;
        } 
        else if (rear == MAX - 1) {
            cout << "Can't enqueue. Queue overflow" << endl;
        }
        else {
            queue[++rear] = element;  // pre-increment
        }
    }

    // Removes an element from the front of the queue. 
    // That location will have zero after dequeueing and 
    // it cannot be accessed directly.
    void dequeue() {
        if (front == -1 && rear == -1) {
            cout << "Can't dequeue. Queue underflow" << endl;
        }
        else if (front == rear) {
            cout << "dequeued: " << queue[front] << endl;
            queue[front] = 0;
            front = -1;  // not sure if it's correct per the college idea
            rear = -1;
        }
        else {
            cout << "dequeued: " << queue[front] << endl;
            queue[front++] = 0;  // post-decrement
        }
    }
    
    // prints from 'front' until 'rear' including rear index
    void displayQueue() {
        if (front == -1 && rear == -1) {
            cout << "Can't display. Queue underflow" << endl;
        }
        else {
            cout << "Queue elements: " << endl;
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << ' ';
            }
            cout << endl;
        }
    }

};

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

    // Edit to return int
    int pop() {
        if (top == -1) {
            cout << "Can't pop. Stackunderflow" << endl;
        }
        else {
            cout << "Pop: " << stack[top] << endl;
            return stack[top--];
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

Queue stackToQueue(Stack &stack) {
    Queue convQueue;
    while (stack.top != -1)
    {
        int value = stack.pop();
        convQueue.enqueue(value);
    }
    return convQueue;
}

int main() {
    Stack stk;
    stk.push(5);
    stk.push(7);
    stk.displayStack();
    Queue q = stackToQueue(stk);
    q.displayQueue();

    return 0;
}