// Insert at the front and at the end in Circular Doubly LinkedList
#include <iostream>
#include <cstdlib>

using namespace std;

// structure of a Node 
struct Node{
  int data ; 
  Node* next ; 
  Node* prev ; 
  
  Node(int x)
  {
      data = x ; 
      next = NULL ;
      prev = NULL ; 
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
    
    Node* temp  = head ;
    
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    
    cout << endl ; 
}

Node* InsertFront(Node* head,int data)
{
    Node* temp = new Node(data);
    
    if(head == NULL){
        head = temp ; 
        head->next = head ; 
        head->prev = head ; 
        return head ;
    }
    
    temp->prev = head->prev ; 
    head->prev->next = temp ; 
    temp->next = head ;
    head->prev = temp ; 
    head = head->prev ; 
    
    return head ;
    
}

Node* InsertEnd(Node* head,int data)
{
    Node* temp = new Node(data);
    
    if(head == NULL){
        head = temp ; 
        head->next = head ; 
        head->prev = head ; 
        return head ;
    }
    
    temp->prev = head->prev ; 
    head->prev->next = temp ; 
    temp->next = head ;
    head->prev = temp ; 
    
    return head ;
    
}

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);
    
    head->next = temp  ; 
    temp->next = temp2 ; 
    temp2->next = head ;
    
    head->prev = temp2 ;
    temp->prev = head ;
    temp2->prev = temp ; 
    
    Display(head);
    head = InsertFront(head,50);
    Display(head);
    head = InsertEnd(head,40);
    Display(head);
    
    return 0; 
}
