// Double Ended Queue Implementation
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

// DEque 
struct DEqueue{
    int size ; 
    Node* front ; 
    Node* rear  ;
    
    DEqueue()
    {
        size = 0 ;
        front = NULL ;
        rear = NULL ;
    }
    
    // push front 
    void push_front(int data)
    {
        Node* temp = new Node(data);
        
        size++;
        
        if(front == NULL)
        {
            front = temp ; 
            rear  = temp ;
            return ;
        }
        
        temp->next = front ; 
        front->prev = temp ; 
        front = temp ;
    }
    
    // push back
    void push_back(int data)
    {
        Node* temp = new Node(data);
        
        size++;
        
        if(front == NULL)
        {
            front = temp ; 
            rear  = temp ; 
            return ;
        }
        
        rear->next = temp ; 
        temp->prev = rear ;
        rear = temp ; 
    }
    
    // pop front 
    void pop_front()
    {
        if(front == NULL)
        {
            cout << "Empty" << endl;
            return ; 
        }
        
        size--;
        
        Node* temp = front;
        
        int data = front->data ; 
        
        cout << data << " is removed" << endl;
        
        if(temp->next == NULL)
        {
            free(temp);
            front = NULL ;
            rear  = NULL ; 
            return ;
        }
        
        front = temp->next ;
        front->prev = NULL ;
        temp->next = NULL ; 
        
        free(temp);
    }
    
    // pop back 
    void pop_back()
    {
        if(rear == NULL)
        {
            cout << "Empty" << endl;
            return ; 
        }
        
        size--;
        
        Node* temp = rear;
        
        int data = rear->data ; 
        
        cout << data << " is removed" << endl;
        
        if(temp->prev == NULL)
        {
            free(temp);
            front = NULL ;
            rear  = NULL ; 
            return ;
        }
        
        rear = temp->prev ;
        rear->next = NULL ;
        temp->prev = NULL ; 
        
        free(temp);
    }
    
    // front data
    void frontData()
    {
        if(front == NULL)
        {
            cout << "No data" << endl;
            return ;
        }
        
        cout << "Data : " << front->data << endl;
    }
    
    // back data 
    void backData()
    {
        if(rear == NULL)
        {
            cout << "No data" << endl; 
            return ; 
        }
        
        cout << "Data : " << rear->data << endl;
    }
    
    // size of the DEqueue
    int getSize()
    {
        return size ;
    }
};

int main()
{
    int data , ch ; 
    
    DEqueue obj;
    
    while(1)
    {
        // operations
        cout << "[1].push_front [2].push_back [3].pop_front [4].pop_back" << endl;
        cout << "[5].front      [6].back      [7].size      [8].Exit    " << endl;
        
        // enter the choice
        cout << "Enter the choice : "; cin >> ch ; 
        
        switch(ch)
        {
            case 1 : cout << "Enter the Data : "; cin >> data ; 
                     obj.push_front(data);
                     cout << endl;
                     break;
                     
            case 2 : cout << "Enter the Data : "; cin >> data ; 
                     obj.push_back(data);
                     cout << endl;
                     break;
                     
            case 3 : obj.pop_front();
                     cout << endl;
                     break;
                     
            case 4 : obj.pop_back();
                     cout << endl;
                     break;
            
            case 5 : obj.frontData();
                     cout << endl;
                     break;
                     
            case 6 : obj.backData();
                     cout << endl;
                     break;
            
            case 7 : cout << "Size : " << obj.getSize() << endl ;
                     cout << endl;
                     break ; 
                     
            case 8 : cout << endl << "Exit" << endl <<  endl;
                     exit(1);
                    
            default : cout << endl << "You have entered wrong choice" << endl << endl;
        }
        
    }
    
    return 0;
}