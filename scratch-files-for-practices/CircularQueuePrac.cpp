#include <iostream>
using namespace std;
#define MAX 5

struct CircularQueue
{
    int queue[MAX];
    int front = -1;
    int rear = -1;

    void enqueue(int value) {
        if ((rear + 1) % MAX == front) {
            cout << "Can't enqueue " << value <<". queueoverflow" << endl;
        }
        else {
            if (front == -1 && rear == -1) {
                front = 0;
                rear = 0;
                queue[rear] = value;
            }
            else {
            rear = (rear + 1) % MAX;
            queue[rear] = value;
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
                queue[front] = 0;
                front = (front + 1) % MAX;
            }
        }
    }

    void displayQueue() {
        if (front == -1 && rear == -1) {
            cout << "Can't display. CircularQueue underflow" << endl;
        } 
        else {
            cout << "CircularQueue elements: " << endl;

            int i = front;
            while (true) {
                cout << queue[i] << ' ';

                // Stop when we reach `rear`
                if (i == rear) {
                    break;
                }

                // Move to the next index in a circular manner
                i = (i + 1) % MAX;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue q;
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
