// Insert the Data at the Given Position
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

Node* InsertPosition(Node* head,int x,int pos)
{
    Node* temp = new Node(x);

    if(pos == 1)
    {
        temp->next = head;
        head = temp;
        return head;
    }

    Node* curr = head;

    for(int i=1;i<=pos-2 && curr != NULL;i++)
    {
        curr = curr->next ; 
    }

    if(curr == NULL)
    {
        return head;
    }

    temp->next = curr->next ; 
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

    int x = 8 , pos = 5 ;

    Display(head);
    head = InsertPosition(head,x,pos);
    Display(head);

    return 0;
}