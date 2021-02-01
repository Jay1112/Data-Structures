// Search the Data in the LinkedList (Recursive)
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

// Search the data in the LinkedList
int Search(Node* head,int data)
{
    static int counter = 0;

    if(head == NULL)
    {
        return -1;
    }

    counter++;

    if(head->data == data)
    {
        return counter;
    }

    return Search(head->next,data);
}

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp;
    temp->next = temp2;

    int data = 30;

    int ch = Search(head,data);

    cout <<  ch << endl;

    return 0;
}