#include <iostream>

using namespace std;

// helper functions 
int left(int i) 
{
	return i*2;   // give index of left child of A[i]
}

int right(int i)
{
	return i*2+1; // give index of right child of A[i]
}

int parent(int i)  
{
	return i/2;  // give index of parent of A[i]
}

// this function will take an array, index, n(which is sizeof(array)/sizeof(int) - 1), because at 0 index, we store total no of nodes
// and i will be any number between [1 n]
void Heapify(int array[], int i, int n)
{
	int lc = left(i);
	int rc = right(i);
	int largest;
	if(lc <= n && array[lc] > array[i])
	     largest = lc;
    else
         largest = i;
    if(rc <= n && array[rc] > array[largest])
        	largest = rc;
    if(largest != i)
    {
    	int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        Heapify(array,largest,n);
    }
}
// this will built heap data structure(in which root has max value from their childs)
void BuiltHeap(int array[], int n)
{
	for(int i = n/2; i >= 1; i--)
	{
		Heapify(array,i,n);
	}
}

// driver function
// this will read element of array from user on run time
// and built heap and then prints out
int main()
{
	int no_of_nodes;
	cout << "enter total no of nodes" << endl;
	cin >> no_of_nodes;
	int array[no_of_nodes+1];
	array[0] = no_of_nodes;
	cout << "enter nodes" << endl;
	for(int i=1 ; i <= no_of_nodes ; i++)
	{
		cin >> array[i];
	}
	cout<<endl;
	BuiltHeap(array,no_of_nodes);
	for(int i = 0; i <= no_of_nodes ; i++)
	      cout << array[i] << " ";
    cout << endl;
	return 0;
}
