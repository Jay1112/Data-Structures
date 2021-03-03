// Priority queue in STL 
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq; // deafult is Max Heap
    
    pq.push(10);
    pq.push(20);
    pq.push(30); // 30 10 20 
    
    cout << pq.size()  << endl; // 3
    cout << pq.top()   << endl; // 30 
    cout << pq.empty() << endl; // 0
    
    // Min Heap 
    priority_queue<int,vector<int>,greater<int>> mhp;
    
    mhp.push(10);
    mhp.push(30);
    mhp.push(20); // 10  30  20
    
    cout << mhp.size()  << endl; // 3
    cout << mhp.top()   << endl; // 10 
    cout << mhp.empty() << endl; // 0
    
    // array to heap conversion
    int arr[3] = { 10 , 5 , 15 };
    
    priority_queue<int> temp(arr,arr+3); // 15 5 10
    
    cout << temp.size()  << endl; // 3
    cout << temp.top()   << endl; // 5 
    cout << temp.empty() << endl; // 0    
    
    return 0;
}
