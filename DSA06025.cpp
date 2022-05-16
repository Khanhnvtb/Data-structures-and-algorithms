#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n, int count)
{
   int i, key, j;
    cout<<"Buoc "<<count<<": "<<arr[0];
    cout<<endl;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
        arr[j+1] = key;
        count++;
        cout<<"Buoc "<<count<<": ";
       	for(int t=0;t<=count;t++){
       		cout<<arr[t]<<" ";
		}
    	cout<<endl;
   }
}
main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int count=0;
	insertionSort(arr,n,count);
}
