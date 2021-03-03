// Stack Implementation using Array
#include<iostream>
#include<cstdlib>

using namespace std;

struct Stack{
    int *st ;
    int capacity ; 
    int top ;

    Stack(int size)
    {
        capacity = size;
        top = -1;
        st = new int[capacity];
    }

    // empty stack checker
    bool empty()
    {
        if(top == -1)
        {
            return true;
        }

        return false;
    }

    // push operation on stack
    void Push(int data)
    {
        if(top == capacity-1)
        {
            cout << "Stack is Full" << endl;
            return ; 
        }

        top = top + 1;

        st[top] = data ; 

        cout << "Data has been inserted." << endl;
    }

    // Pop Operation
    void Pop()
    {
        if(empty())
        {
            cout << "Stack is Empty" << endl;
            return ; 
        }

        int data = st[top];

        top = top - 1;

        cout << data << " is removed." << endl;
    }

    // Display the Stack
    void Display()
    {
        cout << "Stack : " ;

        for(int i=0;i<=top;i++)
        {
            cout << st[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size,ch,data ;

    // enter the capacity of the stack
    cout << "Enter the Stack Capacity : "; cin >> size; 

    // create an object of stack
    Stack obj(size);

    while(1)
    {
        // operations
        cout << "[1].Push [2].Pop [3].Empty [4].Display [5].Exit" << endl;
        
        // enter the choice
        cout << "Enter the Choice : "; cin >> ch ;

        // select the choice
        switch(ch)
        {
            case 1 : cout << "Enter the Data : "; cin >> data ; 
                     obj.Push(data);
                     cout << endl;
                     break;

            case 2 : obj.Pop();
                     cout << endl;
                     break;

            case 3 : if(obj.empty()){
                        cout << "Yes" << endl;
                     }else{
                         cout << "No" << endl;
                     }
                     cout << endl;
                     break;
            
            case 4 : obj.Display();
                     cout << endl;
                     break;

            case 5 : cout << endl << "Exit" << endl;
                     exit(1);

            default : cout << endl << "You have entered wrong choice" << endl;
        }
    }

    return 0;
}