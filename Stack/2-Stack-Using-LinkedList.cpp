// Stack Implementation using LinkedList
#include<iostream>
#include<cstdlib>

using namespace std;

// structure  of a Node
struct Node{
    int data ;
    struct Node* next ; 

    Node()
    {
        next = NULL;
    }

    Node(int x)
    {
        data = x ;
        next = NULL;
    }
};


// Push Operation
Node* Push(Node* head,int data)
{
    Node* temp = new Node(data);

    if(head == NULL)
    {
        head = temp;
        return head;
    }

    temp->next = head;
    head = temp;

    cout << "Data has been inserted" << endl;

    return head;
}

// Pop Operation
Node* Pop(Node* head)
{
    if(head == NULL)
    {
        cout << "Stack is Empty." << endl;
        return head;
    }

    Node* temp = head; 

    int data = temp->data ; 
    
    head = temp->next;
    temp->next = NULL;

    free(temp);

    cout << data << " is removed" << endl;

    return head;
}

// empty stack checker
bool empty(Node* head)
{
    if(head == NULL)
    {
        return true;
    }

    return false;
}

// display the linkedlist
Node* Display(Node* head)
{
    cout << "Stack(LinkedList) : ";

    if(head == NULL)
    {
        cout << "Empty" << endl;
        return head;
    }

    Node* temp = head; 

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    return head;
}

int main()
{

    int ch , data ;

    Node* head = NULL;

    while(1)
    {
        // operations
        cout << "[1].Push [2].Pop [3].Empty [4].Display [5].Exit" << endl;
        
        // enter the choice
        cout << "Enter the Choice : "; cin >> ch ;

        // select the choice
        switch(ch)
        {
            case 1 : cout << "Enter the Data : "; cin >> data ; 
                     head = Push(head,data);
                     cout << endl;
                     break;

            case 2 : head = Pop(head);
                     cout << endl;
                     break;

            case 3 : if(empty(head)){
                        cout << "Yes" << endl;
                     }else{
                         cout << "No" << endl;
                     }
                     cout << endl;
                     break;
            
            case 4 : head = Display(head);
                     cout << endl;
                     break;

            case 5 : cout << endl << "Exit" << endl;
                     exit(1);

            default : cout << endl << "You have entered wrong choice" << endl;
        }
    }
    return 0;
}