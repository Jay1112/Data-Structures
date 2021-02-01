// Insert the Data in the Sorted Manner
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
    cout << "LinkedList : ";

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

Node* SortedInsert(Node* head,int x)
{
    Node* temp =  new Node(x);

    if(head == NULL)
    {
        head = temp;
        return head;
    }

    if(x < head->data)
    {
        temp->next = head;
        head = temp;
        return head;
    }

    Node* curr = head;

    while(curr->next != NULL && curr->next->data < x)
    {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;

    return head;
}

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp;
    temp->next = temp2;

    int x = 32 ;

    Display(head);
    head = SortedInsert(head,x);
    Display(head);

    return 0;
}