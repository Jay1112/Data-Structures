// Nth Node from the End of the LinkedList
#include<iostream>
#include<cstdlib>

using namespace std;

// Structure of the Node
struct Node{
    int data ; 
    Node *next ;

    Node(int x)
    {
        data = x ; 
        next = NULL;
    }
};

// Traverse the LinkedList
void Traverse(Node* head)
{
    cout << "LinkedList : ";

    if(head == NULL)
    {
        cout << "Empty" << endl;
        return ; 
    }

    Node* temp = head ;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Nth node from the end of the linkedlist
void NthFromEnd(Node* head,int pos)
{
    if(head == NULL)
    {
        return ;
    }

    Node* front = head ;

    for(int i=1;i<pos;i++)
    {
        front = front->next;
    }

    if(front == NULL)
    {
        return ; 
    }

    Node* back = NULL;

    while(front != NULL)
    {
        if(back == NULL)
        {
            back = head;
        }
        else
        {
            back = back->next;
        }
        front = front->next;
    }

    cout << "Data : " << back->data << endl;
}

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp;
    temp->next = temp2;

    int pos = 4;

    Traverse(head);

    NthFromEnd(head,pos);

    return 0;
}