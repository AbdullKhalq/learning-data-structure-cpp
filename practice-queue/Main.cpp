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

    /* Removes an element from the front of the queue.
     * That location will have zero after dequeueing even though it cannot be accessed directly.
     */
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
                cout << queue[i] << endl;
            }
        }
    }

};

int main() {
    Queue q;

    // checks if it correctly identify empty queue
    q.displayQueue();  

    // checks if it works properly & handles overflow
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);

    // checks other methods
    q.displayQueue();
    q.dequeue();
    q.displayQueue();

    q.enqueue(7);  // gives overflow because rear is at MAX
    q.displayQueue();


    return 0;
}