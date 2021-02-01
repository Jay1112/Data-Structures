// Traverse the LinkedList (Recursive)
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
    if(head == NULL)
    {
        cout << endl;
        return ; 
    }

    cout << head->data << " ";

    Traverse(head->next);
}

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp;
    temp->next = temp2;

    cout << "LinkedList : ";

    Traverse(head);

    return 0;
}