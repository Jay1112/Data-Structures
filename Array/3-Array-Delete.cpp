// Delete the Data in the array
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

int Delete(int arr[],int size,int x)
{
    if(size == 0)
    {
        return size;
    }

    int index = Search(arr,size,x);

    if(index == -1)
    {
        return size;
    }

    for(int i=index;i<size-1;i++)
    {
        arr[i] = arr[i+1];
    }

    return size-1;
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
    int arr[5] = {10,5,30};
    int size = 3;
    int x = 5;

    Display(arr,size);
    size = Delete(arr,size,x);
    Display(arr,size);

    return 0;
}