// Queue implementation STL
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    
    q.push(10); // 10
    q.push(20); // 10  20
    q.push(30); // 10  20  30
    
    cout << q.front() << " " << q.back() << endl; // 10  30
    
    q.push(40); // 10  20  30  40
    q.pop();    // 20  30  40
    
    cout << q.front() << " " << q.back() << endl; // 20  40
    
    cout << q.size() << endl; // 3 
    
    cout << q.empty() << endl; // 0
    
    return 0 ;
}
