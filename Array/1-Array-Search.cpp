// Return the Index of the Element if it is found otherwise return -1
#include<iostream>
#include<cstdlib>

// Time Complexity :- O(n)
// Aux-Space :- O(1)

using namespace std;

int Search(int arr[],int size,int data)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i] == data)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10,20,30,40,50};
    int size = sizeof(arr)/sizeof(arr[0]);

    int data = 30;

    int index = Search(arr,size,data);

    cout << index << endl;

    return 0;
}