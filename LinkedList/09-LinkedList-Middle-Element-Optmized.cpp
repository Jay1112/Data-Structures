// Middle element of the LinkedList (Optimized) 
#include<iostream>
#include<cstdlib>

using namespace std;

// structure of a node
struct Node{
    int data ;
    Node* next ; 

    Node(int x)
    {
        data = x; 
        next = NULL;
    }
};

void Display(Node* head)
{
    cout << "LinkedList :- ";

    if(head == NULL)
    {
        cout << "Empty" << endl;
        return ;
    }

    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next ; 
    }

    cout << endl;
}

int LengthList(Node* head)
{
    int length = 0 ;
    Node* temp = head; 

    while(temp != NULL)
    {
        temp = temp->next ;
        length++;
    }

    return length;
}

void MiddleElement(Node* head)
{
    if(head == NULL)
    {
        return ;
    }

    Node* slow = head; 
    Node* fast = head; 

    while(fast != NULL && fast->next != NULL )
    {
        slow = slow->next ; 
        fast = fast->next->next; 
    }

    cout << slow->data << endl;
}


int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp;
    temp->next = temp2;

    Display(head);
    MiddleElement(head);

    return 0;
}