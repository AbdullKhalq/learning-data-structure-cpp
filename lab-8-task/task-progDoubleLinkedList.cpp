#include <iostream>
using namespace std;
struct Employee{//like Node in single linked list
    string name;//Like Info in single linked list
    int id;//additional
    Employee *prev, *next;//next: like link in single linked list
};
Employee *temp=NULL, *head=NULL, *tail=NULL, *cur=NULL;


void InsertFront() {
    temp = new Employee;
    cout << "Enter Employee Name:\n";
    cin >> temp->name;
    cout << "Enter Employee ID:\n";
    cin >> temp->id;
    
    if (head == NULL) { // If list is empty
        head = tail = temp;
        temp->next = temp; // Pointing to itself to make circular
        temp->prev = temp;
    } else {
        temp->next = head;
        temp->prev = tail;
        head->prev = temp;
        tail->next = temp;
        head = temp;
    }
}

void InsertRear() {
    temp = new Employee;
    cout << "Enter Employee Name:\n";
    cin >> temp->name;
    cout << "Enter Employee ID:\n";
    cin >> temp->id;
    
    if (head == NULL) { // If list is empty
        head = tail = temp;
        temp->next = temp; // Pointing to itself to make circular
        temp->prev = temp;
    } else {
        temp->prev = tail;
        temp->next = head;
        tail->next = temp;
        head->prev = temp;
        tail = temp;
    }
}

void DeleteFront() {
    if (head == NULL) {
        cout << "List is Empty!!\n";
        return;
    }
    
    temp = head;
    if (head == tail) { // Only one node in the list
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    cout << "Deleted: " << temp->name << " " << temp->id << "\n";
    delete temp;
    cout << endl;
}

void DeleteRear() {
    if (head == NULL) {
        cout << "List is Empty!!\n";
        return;
    }

    temp = tail;
    if (head == tail) { // Only one node in the list
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }
    cout << "Deleted: " << temp->name << " " << temp->id << "\n";
    delete temp;
    cout << endl;
}

void PrintForward() {
    if (head == NULL) {
        cout << "List is Empty!!\n";
        return;
    }

    cout << "List display (forward): \n";
    cur = head;
    do {
        cout << cur->name << " " << cur->id << "\n";
        cur = cur->next;
    } while (cur != head);
    cout << endl;
}

void PrintBackward() {
    if (head == NULL) {
        cout << "List is Empty!!\n";
        return;
    }

    cout << "List display (backward): \n";
    cur = tail;
    do {
        cout << cur->name << " " << cur->id << "\n";
        cur = cur->prev;
    } while (cur != tail);
    cout << endl;
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

