// DEqueue in STL
#include <iostream>
#include <cstdlib>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq;
    
    dq.push_front(5);   //  5
    dq.push_front(10);  //  10  5
    
    dq.push_back(20);   //  10  5  20 
    dq.push_back(30);   //  10  5  20  30 
    
    for(auto x : dq)
    {
        cout << x << " ";
    }
    
    cout << endl;
    
    cout << dq.front() << " " << dq.back() << endl; //  10  30 
    
    cout << dq.size() << endl;  //  4

    dq.pop_front();    //  5  20  30
    
    dq.pop_back();    //  5  20
    
    for(auto x : dq)
    {
        cout << x << " ";
    }    
    
    cout << endl;
    
    return 0;
}