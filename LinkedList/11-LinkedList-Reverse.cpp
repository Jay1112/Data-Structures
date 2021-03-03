// Reverse The LinkedList
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

// Reverse the LinkedList
Node* Reverse(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL)
    {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev ;
    return head;

}

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp;
    temp->next = temp2;

    Traverse(head);
    head = Reverse(head);
    Traverse(head);

    return 0;
}