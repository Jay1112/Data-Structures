// Delete the kth Node in Circular LinkedList
#include <iostream>
#include <cstdlib>

using namespace std;

// structure of a Node 
struct Node{
  int data ; 
  Node* next ; 
  
  Node(int x)
  {
      data = x ; 
      next = NULL ; 
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

Node* DeleteHead(Node* head)
{
    if(head == NULL){
        return head ;
    }
    
    if(head->next == NULL){
        free(head);
        head = NULL;
        return head;
    }
    
    Node* temp = head->next ; 
    
    int t = temp->data ;
    temp->data = head->data ;
    head->data = t ; 
    
    head->next = temp->next ;
    temp->next = NULL ;
    
    free(temp);
    
    return head;
}

Node* DeleteKthNode(Node* head,int k)
{
    if(head == NULL){
        return head ;
    }
    
    if(k == 1){
        return DeleteHead(head);
    }
    
    Node* curr = head ;
    
    for(int i=0;i<k-2;i++)
    {
        curr = curr->next;
    }
    
    if(curr->next == NULL)
    {
        return head;
    }
    
    Node* temp = curr->next ; 
    
    curr->next = temp->next;
    temp->next = NULL ; 
    free(temp);
    
    return head;
}

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);
    
    head->next = temp  ; 
    temp->next = temp2 ; 
    temp2->next = head ;
    
    int k = 4 ;
    
    Display(head);
    head = DeleteKthNode(head,k);
    Display(head);
    
    return 0; 
}