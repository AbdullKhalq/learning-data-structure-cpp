#include <iostream>
using namespace std;
#define MAX 5

struct Queue
{
    int queue[MAX];
    int front = -1;
    int rear = -1;

    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Can't enqueue " << value <<". queueoverflow" << endl;
        }
        else {
            queue[++rear] = value;

            if (front == -1) {
                front++;
            }
        }
    }

    void dequeue() {
        if (front == -1) {
            cout << "Can't dequeue. queueunderflow" << endl;
        }
        else {
            cout << "Dequeue: " << queue[front] << endl;
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front++;
            }
        }
    }

    void displayQueue() {
        if (front == -1) {
            cout << "Can't display. queueunderflow" << endl;
        }
        else {
            cout << "queue elements: "<< endl;
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << ' ';
            }
        cout << endl;
        }
    }

};

int main() {
    Queue q;
    q.displayQueue();
    q.enqueue(5);
    q.enqueue(6);
    q.displayQueue();
    q.dequeue();
    q.displayQueue();
    q.dequeue();
    q.displayQueue();

    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(11);
    q.displayQueue();
    q.enqueue(12);
    q.displayQueue();
    q.dequeue();
    q.displayQueue();


    return 0;
}
