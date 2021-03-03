//  Decrease the key
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

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
          
          // minHeapify function
          void minHeapify(int index)
          {
              int smallest = index ; 
              int lt = left(index);
              int rt = right(index);
              
              if(lt < size && arr[lt] < arr[smallest]){
                  smallest = lt ;
              }
              
              if(rt < size && arr[rt] < arr[smallest]){
                  smallest = rt ;
              }
              
              if(smallest != index){
                  swap(arr[index],arr[smallest]);
                  minHeapify(smallest);
              }
          }

          //  decrease the key function
          void DecreaseKey(int i,int data)
          {
              arr[i] = data ;
              
              while( i!=0 && arr[parent(i)] > arr[i])
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
	int temp[10] = {20,25,30,35,40,80,32,100,70,60};
	MinHeap obj(10);

	for(int i=0;i<10;i++)
	{
		obj.Insert(temp[i]);
	}

	obj.Display();
	
	int i = 3 , data = 5 ; 
	obj.DecreaseKey(i,data);
	
	obj.Display();

	return 0;
}