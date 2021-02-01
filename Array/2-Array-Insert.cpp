// Insert the Data in the array
#include<iostream>
#include<cstdlib>

// Time Complexity :- O(n)
// Aux-Space :- O(1)

using namespace std;

int Insert(int arr[],int size,int cap,int pos,int x)
{
    if(size == cap || pos-1 > size)
    {
        return size;
    }

    int index = pos-1;

    for(int i=size-1;i>=index;i--)
    {
        arr[i+1] = arr[i];
    }

    arr[index] = x;

    return size+1;
}

void Display(int arr[],int size)
{
    cout << "Array : ";

    for(int i=0;i<size;i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[5] = {10,20,30};
    int size = 3;
    int cap = 5;

    int pos = 1;
    int x = 5;

    Display(arr,size);
    size = Insert(arr,size,cap,pos,x);
    Display(arr,size);

    return 0;
}