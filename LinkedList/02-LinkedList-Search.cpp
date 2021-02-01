// Search the Data in the LinkedList
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
    int res = -1 , counter = 0;

    if(head == NULL)
    {
        return res;
    }

    Node* temp = head ;

    while(temp != NULL)
    {
        counter++;
        if(temp->data == data)
        {
            return counter;
        }
        temp = temp->next;
    }

    return res;
}

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp;
    temp->next = temp2;

    int data = 25;

    int ch = Search(head,data);

    cout << ch << endl;

    return 0;
}