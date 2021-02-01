// Delete the Data at the End of the LinkedList
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

Node* DeleteEnd(Node* head)
{
    if(head == NULL)
    {
        return head ;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }

    Node* curr = head ;
    Node* temp ;

    while(curr->next != NULL)
    {
        temp = curr;
        curr = curr->next;
    }

    temp->next = NULL;
    free(curr);

    return head;
}

int main()
{
    Node* head = new Node(10);
    // Node* temp = new Node(20);
    // Node* temp2 = new Node(30);

    // head->next = temp ;
    // temp->next = temp2;

    Display(head);
    head = DeleteEnd(head);
    Display(head);

    return 0;
}