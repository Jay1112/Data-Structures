// Circular Queue Implementation
#include <iostream>
#include <cstdlib>

using namespace std;

// structure of a Queue
struct Queue{
    int cap,size,front;
    int *q ; 
    
    Queue(int c)
    {
        cap = c ; 
        size = 0 ;
        front = 0 ;
        q = new int[cap];
    }
    
    // Methods
    
    // empty checker
    bool isEmpty(){
        
        if(size == 0){
            return true;
        }
        return false;
    }
    
    // full condition checker
    bool isFull(){
        
        if(size == cap){
            return true;
        }
        
        return false;
    }
    
    //  get rear pointer value
    int getRear()
    {
        if(isEmpty()){
            return -1 ; 
        }
        
        return (front + size - 1) % cap;
    }
    
    // enque function
    void enque(int x)
    {
        if(isFull()){
            return ;
        }
        
        int rear = getRear();
        
        rear = (rear + 1) % cap;
        
        q[rear] = x ; 
        
        size++;
    }
    
    // deque function
    void deque()
    {
        if(isEmpty()){
            return ;
        }
        
        int data = q[front];
        
        cout << data << " is removed." << endl;
        
        front = (front + 1) % cap;
        
        size--;
    }
    
    // print the whole queue
    void print()
    {
        cout << "Queue : ";
        
        if(isEmpty()){
            
            cout << "Empty" << endl;
            return ; 
            
        }
        
        int start = front ; 
        int end = getRear();
        
        while(1){
            cout << q[start] << " " ;
            
            if(start == end)
            {
                break;
            }
            
            start = (start + 1) % cap;
        }
        
        cout << endl;
    }
    
    // get the size of the Queue
    int getSize(){
        return size;
    }
    
};

int main()
{
    int capacity,ch,data; 
    
    cout << "Enter the capacity : "; cin >> capacity ;
    
    // objet of a Queue
    Queue obj(capacity);
    
    while(1)
    {
        // operations
        cout << "[1].Enque [2].Deque [3].isEmpty [4].isFull " << endl;
        cout << "[5].Size  [6].Print [7].Exit               " << endl;
        
        // enter the choice 
        cout << "enter the choice : "; cin >> ch ; 
        
        switch(ch)
        {
            case 1 : cout << "Enter the Data : "; cin >> data ; 
                     obj.enque(data);
                     cout << endl;
                     break;
                     
            case 2 : obj.deque();
                     cout << endl;
                     break;
                     
            case 3 : if(obj.isEmpty()){
                        cout << "Yes" << endl; 
                     }else{
                         cout << "No" << endl;
                     }
                     break;
                     
            case 4 : if(obj.isFull()){
                        cout << "Yes" << endl; 
                     }else{
                         cout << "No" << endl;
                     }
                     break;
                     
            case 5 : cout << "Size : " << obj.getSize() << endl;
                     cout << endl;
                     break;
                     
            case 6 : obj.print(); 
                     cout << endl;
                     break;
                     
            case 7 : cout << endl << "Exit" << endl << endl;
                     exit(1);
                     
                     
            default : cout << endl << "You have entered wrong choice" << endl << endl;
        }
    }
    
    return 0;
}