// Insert an Element in Binary-Heap
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Min Heap Class
class MinHeap{
public :
          int *arr ; 
          int size ; 
          int capacity ; 

          // constuctor
          MinHeap(int c)
          {
          	  arr = new int[c];
          	  size = 0;
          	  capacity = c;
          }

          // left side node index
          int left(int i)
          {
          	  return 2*i + 1 ; 
          }

          // right size node index
          int right(int i)
          {
          	return 2*i + 2 ;
          }

          // parent node index
          int parent(int i)
          {
          	return (i-1)/2;
          }

          // Inset Function
          void Insert(int x)
          {
          	  if(size == capacity){
          	  	return ;
          	  }

          	  size++;
          	  arr[size-1] = x ;

          	  for(int i=size-1; i!=0 && arr[parent(i)] > arr[i];)
          	  {
          	  	  swap(arr[i],arr[parent(i)]);
          	  	  i = parent(i);
          	  }

          }

          // Display function
          void Display()
          {
          	  cout << "Heap : ";

          	  for(int i=0;i<size;i++)
          	  {
          	  	cout << arr[i] << " ";
          	  }

          	  cout << endl;
          }
};

int main()
{
	int data = 12;
	int temp[8] = {10,20,15,40,50,100,25,45};
	MinHeap obj(10);

	for(int i=0;i<8;i++)
	{
		obj.Insert(temp[i]);
	}

	obj.Display();
	obj.Insert(data);
	obj.Display();

	return 0;
}
