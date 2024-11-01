#include <iostream>
using namespace std;
#define MAX 5

struct Queue
{
    int queue[MAX];
    int front = -1;
    int rear = -1;

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
            queue[++rear] = element;
        }
    }

    void dequeue() {
        if (front == -1 && rear == -1) {
            cout << "Can't dequeue. Queue underflow" << endl;
        }
        else if (front == rear) {
            cout << "dequeued: " << queue[front] << endl;
            front = -1;
            rear = -1;
        }
        else {
            cout << "dequeued: " << queue[front--] << endl;
        }
    }
    
    void displayQueue() {
        if (front == -1 && rear == -1) {
            cout << "Can't display. Queue underflow" << endl;
        }
        else {
            cout << "Queue elements: " << endl;
            for (int i = 0; i <= rear; i++) {
                cout << queue[i] << endl;
            }
        }
    }

};

int main() {
    Queue q;

    q.displayQueue();

    q.enqueue(5);
    q.enqueue(5);
    q.displayQueue();
    q.dequeue();
    q.displayQueue();
    q.enqueue(7);
    q.displayQueue();


    return 0;
}