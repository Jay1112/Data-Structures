// Reverse the Array
#include<iostream>
#include<cstdlib>

// Time Complexity :- O(n)
// Aux-Space :- O(1)

using namespace std;

int Reverse(int arr[],int size)
{
    for(int i=0;i<size/2;i++)
    {
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
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
    int arr[] = {10,20,30,40,50};
    int size = sizeof(arr)/sizeof(arr[0]);

    Display(arr,size);
    Reverse(arr,size);
    Display(arr,size);

    return 0;
}