// Queue implementation using LinkedList
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

// structure of a Queue
struct Queue{
    int size ; 
    Node* front ; 
    Node* rear  ;
    
    Queue()
    {
        size = 0 ;
        front = NULL ; 
        rear = NULL ;
    }
    
    // isEmpty function
    bool isEmpty()
    {
        if(front == NULL)
        {
            return true;
        }
        
        return false;
    }
    
    // get the size of the LinkedList
    int getSize()
    {
        return size ;
    }
    
    // enque 
    void enque(int data)
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
        rear = temp ; 
    }
    
    // deque
    void deque()
    {
        if(front == NULL)
        {
            cout << "Queue is Empty" << endl;
            return ; 
        }
        
        size--;
        
        Node* temp = front ;
        
        int data = temp->data ; 
        cout << data << " is removed" << endl;
        
        if(front->next == NULL)
        {
            free(front);
            front = NULL ; 
            rear = NULL;
            return ;
        }
        
        front = front->next ; 
        
        free(temp);
        
        
    }
    
    // display the Queue
    void display()
    {
        cout << "Queue : ";
        
        if(isEmpty())
        {
            cout << "Empty" << endl;
            return ; 
        }
        
        Node* temp = front ; 
        
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next ; 
        }
        
        cout <<  endl;
    }
};

int main()
{
    int data,ch ;
    
    struct Queue obj;
    
    while(1)
    {
        // operations
        cout << "[1].Enque [2].Deque   [3].isEmpty" << endl ; 
        cout << "[4].Size  [5].Display [6].Exit   " << endl ;
        
        // enter the choice 
        cout << "Enter the Choice : "; cin >> ch ; 
        
        switch(ch)
        {
            case 1 :  cout << "Enter the Data : "; cin >> data ;
                      obj.enque(data);
                      cout << endl;
                      break;
                      
            case 2 :  obj.deque();
                      cout << endl;
                      break;
                      
            case 3 :  if(obj.isEmpty()){
                        cout << "Yes" << endl;  
                      }else{
                          cout << "No" << endl;
                      }
                      cout << endl;
                      break;
                      
            case 4 :  cout << "Size : " << obj.getSize() << endl;
                      cout << endl;
                      break;
                     
            case 5 :  obj.display();
                      cout << endl;
                      break ;
                      
            case 6 :  cout << endl << "Exit" << endl << endl;
                      exit(1);
            
            default : cout << "You have entered wrong choice" << endl; 
            
        }
    }
    
    return 0;
}