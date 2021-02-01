// Traverse the LinkedList 
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

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp;
    temp->next = temp2;

    Traverse(head);

    return 0;
}