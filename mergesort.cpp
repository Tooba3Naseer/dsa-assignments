#include <iostream>

using namespace std;

void Merge(int B[], int p,int C[],int q, int A[], int n);
void MergeSort(int A[], int n);

void MergeSort(int A[], int n)
{
	if (n > 1)
	{
		int len = n/2;
		int B[len];
		int C[n-len];
		for(int i=0 ; i < len ; i++)
		{
			B[i] = A[i];
		}
		int k = 0;
		for(int i = len; i < n ; i++)
		{
			C[k] = A[i];
			k++;
		}
		MergeSort(B,len);
		MergeSort(C, n-len);
		Merge(B,len,C,n-len,A,n);
	}
}

void Merge(int B[], int p,int C[],int q, int A[], int n)
{
	int i,j,k = 0;
	while(i < p && j < q)
	{
		if(B[i] <= C[j])
		{
			A[k] = B[i];
			i++;
		}
		else
		{
			A[k] = C[j];
			j++;
		}
		k++;
	}
	if(i==p)
	{
		for(int index = j ; index <  q ; index++)
		{
			A[k] = C[index];
			k++;
		}
	}
	else
	{
		for(int index = i ; index <  p ; index++)
		{
			A[k] = B[index];
			k++;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int array[n];
	for(int i = 0; i < n ; i++)
	{
		cin >> array[i];
	}
	cout << endl;
	MergeSort(array,n);
	for(int i = 0; i < n ; i++)
	{
		cout << array[i] << endl;
	}
   return 0;	
}

