#include <iostream> 
using namespace std; 
#define MAX 20 

////////////////////////////////////// stack code -from here
struct Stack
{
	// write code here
};

void push(Stack &st,int data)
{
	// write code here
}

int pop(Stack &st)
{
	// write code here
}
////////////////////////////////////// stack code -to here
/************************************/
////////////////////////////////////// queue code -from here
struct Queue 
{
	// write code here
}; 

bool IsEmpty(Queue &q)// new *********
{
	// write code here
}

void enqueue(Queue &q, int data) 
{  
	// write code here 		
}

int dequeue(Queue &q) 
{ 
    // write code here  
}

void display(Queue &q) 
{ 
	// write code here
}

////////////////////////////////////// queue code -to here

void reverse(Queue &q, Stack &st) // New one
{
	cout << "\nReverse Queue: ";
	
	//write code here to dequeue data from the queue to push it to the stack
	
	//write code here to pop data from the stack to enqueue it to the queue 
	
	// write code here to call display function			
}

int main() 
{
	// write code here for stack definition
	
	// write code here for queue definition
	
	int N,data;
	
	cout << "Enter N: ";
	cin >> N;
	
	cout << "Enter " << N << " Integer values: ";
	// write code here to store data into queue
	
	// write code here to call reverse function
	
	return 0; 
}

