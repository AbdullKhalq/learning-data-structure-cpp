/*
Lucy and Jade are playing a game. 
Both of them are initially provided with a list of n numbers.
(Both have the same list but their own copy).
Now, they both have a different strategy to play the game. 
Lucy picks the element from start of her list. 
Jade picks from the end of his list. 
You need to generate the result in form of an output list.

Method to be followed at each step to build the output list is:
•	If the number picked by Lucy is bigger than Jade
 then this step's output is 1. 
 Jade removes the number that was picked from their list.
•	If the number picked by Lucy is smaller than Jade 
then this step's output is 2. 
Lucy removes the number that was picked from their list.
•	If both have the same number then this step's output is 0.
Both Lucy and Jade remove the number that was picked from their list.

This game ends when at least one of them has no more elements to be picked
i.e. when the list gets empty. Output the built output list

Explanation:
1st step: Lucy picks 1. Jade picks 3. Jade > Lucy. 
    So output is 2. Lucy removes 1.
2nd step: Lucy picks 2. Jade picks 3. Jade > Lucy. 
    So output is 2. Lucy removes 2.
3rd step: Lucy picks 3. Jade picks 3. Jade = Lucy. 
    So output is 0. Lucy removes 3. Jade removes 3.

Output list: [2, 2, 0

Suggested:
    - after making stack for both Lucy and Jade, change TOP indicator
    to 0 for lucy and n-1 for Jade
    - Make Lucy a list and Jade a stack
*/

#include <iostream>
using namespace std;

class Stack
{
private:
    int* stack;
    int top;
    int capacity;
public:
    Stack() {
        capacity = 5;
        stack = new int[capacity];
        top = -1;
    }

    Stack(int size) {
        capacity = size;
        stack = new int[capacity];
        top = -1;
    }

    void setTop(int top) {
        this->top = top;
    }

    int getTop() {
        return top;
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

class Player
{
private:
    int* listOfElementsPtr;
    char strategy;
public:
    Player(int list[], char strategy) {
        this->listOfElementsPtr = list;
        this->strategy = strategy;
    };

    ~Player();

    void strategy() {
        if (strategy == 'L')
        {
            /* code */
        }
        else
        {
            /* code */
        }
    }

    void lucyStrategy(Stack stk) {
        stk.setTop(0);
    }
};


int main () {

    return 0;
}