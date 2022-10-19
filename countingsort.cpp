#include<iostream>

 using namespace std;
 
 void countingsort(int A[], int B[], int k, int n)
 {
 	int C[k+1];
 	for(int i = 0; i <= k; i++)
 	   C[i] = 0;
 	for(int j = 1 ; j <= n; j++)
 	   C[A[j]]=C[A[j]]+1;
 	for(int i =1; i <= k; i++)
 	   C[i] = C[i] + C[i-1];
    for(int j = n ; j >= 1; j--)
      {
	     B[C[A[j]]] = A[j];
         C[A[j]]=C[A[j]]-1;
      }
 }


int main()
{
    int n,k;
    cout << "enter no of elements" << endl;
    cin >>n;
    int array[n+1];
    array[0] = n;
    for(int i = 1; i <=n ; i++)
        cin >> array[i];
    cout << "enter max element in your given array" << endl;
    cin >> k;
    int B[n+1];
    B[0] = n;
    countingsort(array,B,k,n);
    for(int i=0; i <= n ; i++)
       cout << B[i] << " ";
    cout << endl;
    return 0;
 
}
