// Insert at the Front of the Circular LinkedList
#include <iostream>
#include <cstdlib>

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
    cout << "LinkedList : ";
    
    if(head == NULL){
        cout << "Empty" << endl;
        return ;
    }
    
    Node* temp = head ;
    
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    
    cout << endl;
}

Node* InsertFront(Node* head,int data)
{
    Node* temp = new Node(data);
    
    if(head == NULL)
    {
        head = temp ;
        head->next = head ;
        return head ;
    }
    
    temp->next = head->next;
    head->next = temp;
    
    int t = temp->data ; 
    temp->data = head->data ;
    head->data = t ;
    
    return head;
}

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);
    
    head->next = temp ; 
    temp->next = temp2 ;
    temp2->next = head ;
    
    int data = 50 ; 
    
    Display(head);
    head = InsertFront(head,data);
    Display(head);
    
    return 0;
}