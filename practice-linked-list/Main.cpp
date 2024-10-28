#include <iostream>
using namespace std;

struct Node
{
    int value = 0;
    Node* nextItem = NULL;
};

Node* head = NULL;

void insertNode(int data) {
    Node* newNode;
    Node* lastNode;

    newNode = new Node;
    newNode->value = data;

    /*
    First 'if' only runs on first insertion
    After that, the lastNode pointer will travel along the nodes 
    until it reaches a node that has no next node (last node has no next)
    finally, the new node becomes the new last node so its nextItem is null
    */
    if (head == NULL) {
        head = newNode;  // head and newNode are pointers
        newNode->nextItem = NULL;
    }
    else {
        lastNode = head;
        while (lastNode->nextItem != NULL) {
            lastNode = lastNode->nextItem;
        }
        
        // gives old last node the address of new last node
        lastNode->nextItem = newNode;
        newNode->nextItem = NULL;
    }
}

int main() {
    Node n1;
    

    return 0;
}