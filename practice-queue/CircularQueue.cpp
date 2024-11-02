#include <iostream>
using namespace std;
#define MAX 5

/*
    Uses a special "position + 1 % MAX" to find the next index we can use
    
    Example: 
    if Front is 0, next index will be 2.
    if Rear is at MAX - 1, next index will be 0 (wrapped around)
*/
struct CircularQueue
{
    int circularQueue[MAX];
    int front = -1;
    int rear = -1;

    // Adds an element to the rear of the circularQueue
    void enqueue(int element) {

        // when circularQueue is empty
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
            circularQueue[rear] = element;
        }
        
        // Check if the queue is full
        else if ((rear + 1) % MAX == front) {
            cout << "Can't enqueue. circularQueue overflow" << endl;
        }
        // Enqueue by incrementing rear or wrapping it around
        else {
            rear = (rear + 1) % MAX;
            circularQueue[rear] = element;
        }
    }

    /* Removes an element from the front of the circularQueue.
     * That location will have zero after dequeueing
     * even though it cannot be accessed directly.
     */
    void dequeue() {
        if (front == -1 && rear == -1) {
            cout << "Can't dequeue. circularQueue underflow" << endl;
        } 
        else {
            // dequeues an element then edits front or rear and front
            // depending on the situation
            cout << "dequeued: " << circularQueue[front] << endl;
            circularQueue[front] = 0;

            if (front == rear) {  // Queue is now empty after dequeue
                front = -1;
                rear = -1;
            } 
            else {
                front = (front + 1) % MAX;
            }
        }
    }

    
    void displayCircularQueue() {
    if (front == -1 && rear == -1) {
        cout << "Can't display. CircularQueue underflow" << endl;
    } 
    else {
        cout << "CircularQueue elements: " << endl;

        int i = front;
        while (true) {
            cout << circularQueue[i] << endl;

            // Stop when we reach `rear`
            if (i == rear) {
                break;
            }

            // Move to the next index in a circular manner
            i = (i + 1) % MAX;
        }
    }
}

};

int main() {
    CircularQueue q;

    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(10);
    q.enqueue(135);
    q.enqueue(20);

    q.displayCircularQueue();
    q.dequeue();
    q.displayCircularQueue();
    q.enqueue(18);
    q.displayCircularQueue();

    return 0;
}