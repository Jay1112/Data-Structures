// minHeapify function 
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
	int temp[10] = {40,20,30,35,25,80,32,100,70,60};
	int index = 0 ;
	MinHeap obj(10);
	
	obj.size = 10 ;

	for(int i=0;i<10;i++)
	{
		obj.arr[i] = temp[i] ;
	}

	obj.Display();
	obj.minHeapify(index);
	obj.Display();

	return 0;
}