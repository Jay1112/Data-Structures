// Nth node from the end of the LinkedList
#include<iostream>
#include<cstdlib>

using namespace std;

// structure of a node
struct Node{
    int data ; 
    Node* next ;
    
    Node(int x)
    {
        data = x ;
        next = NULL;
    }
};

void Display(Node* head)
{
    Node* temp = head;
    
    if(head == NULL)
    {
        cout << "Empty" << endl;
        return ;
    }
    
    cout << "LinkedList : " ;
    
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    cout << endl;
}

int getLength(Node* head)
{
    int length = 0;
    Node* temp = head;
    
    while(temp != NULL)
    {
        length++;
        temp = temp->next ;
    }
    
    return length;
}

void NthFromEnd(Node* head,int pos)
{
    if(head == NULL)
    {
        return ; 
    }
    
    int length = getLength(head);
    
    if(pos > length)
    {
        cout << "Position is wrong." << endl;
        return ;        
    }
    
    Node* temp = head;
    
    for(int i=1;i<=length-pos;i++)
    {
        if(temp == NULL)
        {
            cout << "Position is wrong." << endl;
            return ;
        }
        temp = temp->next;
    }
    
    cout << "Data : " << temp->data << endl;
}

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);
    
    head->next = temp;
    temp->next = temp2;
    
    int pos = 4;
    
    Display(head);
    
    NthFromEnd(head,pos);
    
    return 0;
}