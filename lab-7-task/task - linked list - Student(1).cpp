#include <iostream>
using namespace std;
struct Node{
    int info;
    Node *link;
};
Node *temp=NULL, *cur=NULL, *head=NULL, *tail=NULL;
Node *Searched=NULL;//new******************************************
void InsertFront()//insert to head
{
	//////////////////////////////
	//Preparing the new Node
    temp = new Node;
    cout<<"Enter Integer Data:\n";
    cin>>temp->info;
    temp->link=NULL;
    //////////////////////////////    
    if (head==NULL)//if list empty
    {
        head=temp;
        tail=temp;
    }
    else//insert @ first (front)
    {
        temp->link=head;
        head=temp;
    }
}
void InsertRear()//insert to tail
{
	//////////////////////////////
	//Preparing the new Node
    temp=new Node;
    cout<<"Enter Integer Data:\n";
    cin>> temp->info;
    temp->link=NULL;
    //////////////////////////////     
    if (head==NULL)//if list empty
    {
        head=temp;
        tail=temp;
    }
    else
    {//insert @ last (rear)
        tail->link=temp;
        tail=temp;
    }
}
void DeleteFront()//delete from head
{
    temp = head;
    if(head==NULL)
    {
      cout<<"List is Empty!!\n";
    }
    else
    {
        if(head->link==NULL)//if list has only one item 
        {//list become empty
            head=NULL;
            tail=NULL;
        }
        else
        {//else remove the head
            head = head->link;
        }
        cout<<"Deleted:"<<temp->info <<"\n";
        delete temp;
    }
    cout<<endl;
}
void DeleteRear()//delete from tail
{

    cur=head;
    temp=tail;

    if(head==NULL)
    {
       cout<< "List is Empty!!\n";
    }

    else
    {
        if(head->link==NULL)//if list has only one item 
        {//list become empty
            head=NULL;
            tail=NULL;
        }
        else// remove the tail when reach the node before tail
        {
            while(cur->link!=tail)//To reach the node before tail
            	cur=cur->link;
            tail=cur;//let tail back to previous node
            cur->link=NULL;
        }
        cout<<"Deleted: "<<temp->info << "\n";
        delete temp;
    }
    cout<<endl;
}
void PrintForward()//from head to tail
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
            cout<< cur->info<<"\t";
            cur=cur->link;
        }
        cout<<endl;
    }
}
// add Node *Searched=NULL; @ begining
bool Search(int value)
{
	//at fisrt check if list is empty
	//if not sreach intil found, if founded return true else return false
}
void DeleteSpNode()//like delete from tail
{
	//at fisrt check if list is empty
	//if not,,, enter the value to search
	//	if seach function return true => remove it and print its info 
	//	if not print "Not deleted ....the value not founded in the list"
}
void InsertAfter()
{
	//enter the value to insert after (searched vlaue)
	//	if seach function return true => create new node and add it after the searched node
	//	if not print "Not insert ....the value not founded in the list"
}
int main(){
    int choice;
    
    do{
        cout << "\n**linked list Menu**\n";
        cout << "1: Insert item at front\n";
        cout << "2: Insert item at rear\n";
        cout << "3: Delete item from front\n";
        cout << "4: Delete item from rear\n";
        cout << "5: Print List in forward direction\n";
        cout << "6: Search for a value\n";				//new*****************
        cout << "7: Insert after specific Node\n";		//new*****************
        cout << "8: Delete specific Node\n";			//new*****************
        cout << "9: Exit\n";
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
        case 6:	//new*****************
        		int value;
				cout << "\nEnter value to search: ";
				cin >> value;
               	if(Search(value))
               		cout << "\nYes .... founded in list\n";
            	else
            		cout << "\nNo .... not founded in list\n";
               break;
        case 7: //new*****************
               InsertAfter();
               break;
        case 8: //new*****************
               DeleteSpNode();
               break;
        case 9:
               cout<<"Exiting Program\n";
               break;
        default:
            cout<<"Error! wrong choice\n";
       }
    }while (choice!=9);

    return 0;
}

