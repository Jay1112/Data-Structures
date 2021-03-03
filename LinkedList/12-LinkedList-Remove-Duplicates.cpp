// Remove Duplicates from the LinkedList
#include<iostream>
#include<cstdlib>

using namespace std;

// structure of the Node
struct Node{
  int data ; 
  Node* next ;
  
  Node(int x)
  {
      data = x ;
      next = NULL;
  }
};

Node* RemoveDuplicates(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    Node* curr = head;
    Node* temp = curr->next ;
    
    while(temp != NULL)
    {
        if(curr->data == temp->data)
        {
            curr->next = temp->next;
            temp->next = NULL;
            free(temp);
            temp = curr->next;
        }
        else
        {
            curr = curr->next;
            temp = temp->next;
        }
    }
    
    return head;
}

void Display(Node* head)
{
    if(head ==  NULL)
    {
        cout << "Empty" << endl;
        return ; 
    }
    
    cout << "LinkedList : " ;
    
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
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(20);
    Node* d = new Node(20);
    Node* e = new Node(30);
    Node* f = new Node(30);
    
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    
    Node* prev = NULL ;
    
    Display(head);
    head = RemoveDuplicates(head);
    Display(head);
    
    return 0;
}