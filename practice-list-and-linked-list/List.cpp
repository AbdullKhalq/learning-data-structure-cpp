#include <iostream>
using namespace std;

// A box which contains a value and a pointer to next node.
struct Node {
    int value;
    Node *nextNode = NULL;
};

struct LinkedList
{
    Node *head = NULL;
    Node *tail = NULL;

    // Prompts client to enter a value and inserts at rear
    void insertAtRear() {
        Node *newNode = new Node;

        cout << "Enter integer value: ";
        cin >> newNode->value;

        // Check if the list is empty
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        // When the list has items
        else {
            tail->nextNode = newNode;
            tail = newNode;
        }
    }

    // Prompts client to enter a value and inserts at front
    void insertAtFront() {
        Node *newNode = new Node;

        cout << "Enter integer value: ";
        cin >> newNode->value;

        // If the list is empty
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        // When the list has items
        else {
            newNode->nextNode = head;  // Point new node to current head
            head = newNode;  // Update head to new node
        }
    }

    // Delete first item
    void deleteAtFront() {

        // If the list is empty
        if (head == NULL) {
            cout << "Can't deleteAtFront. List is empty" << endl;
        }
        // When the list has items. temporarily store to be deleted
        // node. 
        // Then, points head to nextNode if exist otherwise NULL
        else if (head->nextNode == NULL) {
            Node *tempNode = head;
            head = NULL;
            tempNode->nextNode = NULL;
            delete(tempNode);
        }
        else {
            Node *tempNode = head;
            head = head->nextNode;
            tempNode->nextNode = NULL;
            delete(tempNode);
        }
    }

    // Delete last item
    void deleteAtRear() {

        // If the list is empty
        if (head == NULL) {
            cout << "Can't deleteAtFront. List is empty" << endl;
        }
        // When the list has items. temporarily store to be deleted
        // node. 
        // Then, points head to nextNode if exist otherwise NULL
        else if (head->nextNode == NULL) {
            Node *tempNode = head;
            head = NULL;
            tempNode->nextNode = NULL;
            delete(tempNode);
        }
        else {
            Node *tempNode = head;
            head = head->nextNode;
            tempNode->nextNode = NULL;
            delete(tempNode);
        }
    }

    // Print items from head to tail while the nextNode pointer
    // is not NULL which means it is the last node.
    void displayList() {

        if (head == NULL) {
            cout << "Can't displayList. List is empty"  << endl;
        }
        else {
            Node *currentNode = head;
            cout << "Linked List items: " << endl;
            while (currentNode != NULL) {
                cout << currentNode->value << ' ';
                currentNode = currentNode->nextNode;
            }
            cout << endl;
        }
    }
};


int main() {
    LinkedList list;
    list.insertAtRear();
    list.insertAtFront();

    
    list.displayList();

    list.deleteAtFront();
    list.displayList();

    return 0;
}