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

void insertNodeonHeap(int array[],int n, int d)
{
	array[0] = n+1;
	if (n==0)
	   array[1] = d;
	else
	{
	      int ch = n+1;
	      array[ch] = d;
	      int pr = parent(ch);
	      while(pr != 0 && array[pr] < array[ch])
	      {
	      	int temp = array[ch];
	      	array[ch] = array[pr];
	      	array[pr] = temp;
	      	ch = pr;
	      	pr = parent(pr);
	      }
	}
}

void replacementofNode(int array[],int d, int n)
{
	if(n==0)
	   return;
	if (n==1)
	   array[1] = d;
	else
	   {
	   	int t = 1;
	   	array[t] = d;
	   	int lc = left(t);
	   	int rc = right(t);
	   	while(array[t] < array[lc] || array[t] < array[rc] )
	   	{
	   		int largest;
	   		if(lc <=n && array[lc] > array[t])
	   		    largest = lc;
	   		else
	   		    largest = t;
	   		if(rc <= n && array[rc] > array[largest])
	   		    largest = rc;
	   		if(largest != t)
	   		{
	   		int temp = array[largest];
	   		array[largest] = array[t];
			array[t] = temp;
			t = largest;
			lc = left(t);
			rc = right(t);
		    }
		    else
		      return;
	   	}
	   }
}


void deletefromRoot(int array[],int n)
{
	int replace = array[n];
	replacementofNode(array,replace,n-1);	
}


int main()
{
	int no_of_nodes,d;
	cout << "enter total no of nodes" << endl;
	cin >> no_of_nodes;
	int array[no_of_nodes+1];
	array[0] = no_of_nodes;
	cout << "enter nodes of heap data structure " << endl;
	for(int i=1 ; i <= no_of_nodes ; i++)
	{
		cin >> array[i];
	}
	cout<<"enter element which you want to insert" << endl;
	cin >> d;
	insertNodeonHeap(array,no_of_nodes,d);
	for(int i = 0; i <= no_of_nodes+1 ; i++)
	      cout << array[i] << " ";
    cout << endl;
    
    int n = no_of_nodes+1;
    cout << "enter node to replace the root" << endl;
    cin >> d;
    replacementofNode(array,d,n);
    for(int i = 0; i <= n ; i++)
	      cout << array[i] << " ";
    cout << endl;
    
    cout<<"now delete the root" << endl;
    array[0]= n-1;
    deletefromRoot(array,n);
    for(int i = 0; i <= n-1 ; i++)
	      cout << array[i] << " ";
    cout << endl;
	return 0;
}
