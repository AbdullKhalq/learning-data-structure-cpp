#include <iostream>
using namespace std;
struct Employee{//like Node in single linked list
    string name;//Like Info in single linked list
    int id;//additional
    Employee *prev, *next;//next: like link in single linked list
};
Employee *temp=NULL, *head=NULL, *tail=NULL, *cur=NULL;

void InsertFront()
{
	//////////////////////////////
	//Preparing the new Employee (Node)
    temp = new Employee;
    cout<<"Enter Employee Name:\n";
    cin>>temp->name;
    cout<<"Enter Employee ID:\n";
    cin>>temp->id;
    temp->prev=NULL;//new
    temp->next=NULL;//like link in single linked list 
    //////////////////////////////
    if (head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;//new
        head=temp;
        head->prev = tail;  // Addition: To make it circular
    }
}

void InsertRear()
{
	//////////////////////////////
	//Preparing the new Employee (Node)
    temp = new Employee;
    cout<<"Enter Employee Name:\n";
    cin>>temp->name;
    cout<<"Enter Employee ID:\n";
    cin>>temp->id;
    temp->prev=NULL;
    temp->next=NULL;
	//////////////////////////////
    if (head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        temp->prev=tail;//new
        tail=temp;
        tail->next = head; // Addition: To make it circular
    }
}

void DeleteFront()
{
    temp = head;
    if(head==NULL)
      cout<<"List is Empty!!\n";
    else
    {
        if(head->next==NULL)//if list has only one item 
        {//list become empty
            head=NULL;
            tail=NULL;
        }
        else
        {
            head = head->next;
            head->prev = tail; // edited: head->prev = NULL; --> head->prev = tail
        }
        cout<<"Deleted:"<<temp->name << " " <<temp->id <<"\n";
        delete temp;
    }
    cout<<endl;
}

void DeleteRear()
{
    temp=tail;
    if(head==NULL)
       cout<< "List is Empty!!\n";
    else
    {
        if(head->next==NULL)//if list has only one item 
        {//list become empty
            head=NULL;
            tail=NULL;
        }
        else
        {//here no need to reach the prev Node
                tail=tail->prev;
                tail->next=head;  // edited: tail->next=NULL; --> head
        }
           cout<<"Deleted:"<<temp->name << " " <<temp->id <<"\n";
           delete temp;
    }
    cout<<endl;
}

void PrintForward()
{
    cur=head;

    if(head==NULL)
    {
        cout<<"List is Empty!!\n";
    }
    else
    {
        cout<<"List display: \n";
        while(cur!=NULL)
        {
            cout<< cur->name <<" " <<cur->id <<"\n";
            cur=cur->next;//Forward
        }
        cout<<endl;
    }
}

void PrintBackward()
{
    cur=tail;

    if(head==NULL)
    {
        cout<<"List is Empty!!\n";
    }
    else
    {
        cout<<"List display: \n";
        while(cur!=NULL)
        {
            cout<< cur->name <<" " <<cur->id <<"\n";
            cur=cur->prev;//Backward
        }
        cout<<endl;
    }
}

int main(){
    int choice;
    
    do{
        cout << "1: Insert item at front\n";
        cout << "2: Insert item at rear\n";
        cout << "3: Delete item from front\n";
        cout << "4: Delete item from rear\n";
        cout << "5: Print List in forward direction\n";
        cout << "6: Print List in backward direction\n";
        cout << "7: Exit\n";
        cout << "Enter your choice: \n";
        cin>>choice;
        
        switch (choice){
        case 1:
               InsertFront();
               break;
        case 2:
               InsertRear();
               break;
        case 3:
               DeleteFront();
               break;
        case 4:
               DeleteRear();
               break;
        case 5:
               PrintForward();
               break;
        case 6:
               PrintBackward();
               break;

        case 7:
               cout<<"Exiting Program\n";
               break;
        default:
            cout<<"Error! wrong choice\n";
       }
    }while (choice!=7);

    return 0;
}

