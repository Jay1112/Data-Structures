// Insert the Data at the Front of the LinkedList
#include<iostream>
#include<cstdlib>

using namespace std;

// structure of a Node
struct Node{
    int data ;
    struct Node *next ;

    Node(int x)
    {
        data = x ;
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
        temp = temp->next;
    }

    cout << endl;
}

Node* InsertFront(Node* head,int data)
{
    Node* temp = new Node(data);

    if(head == NULL)
    {
        head = temp ;
        return head ;
    }

    temp->next = head;
    head = temp;

    return head;
}

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp ;
    temp->next = temp2;

    int data = 55;

    Display(head);
    head = InsertFront(head,data);
    Display(head);

    return 0;
}