#include<bits/stdc++.h>
using namespace std;
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
void selectionSort(int arr[], int n,int count)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
    count++;
    min_idx = i;
    for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
        min_idx = j;
        swap(arr[min_idx], arr[i]);
        cout<<"Buoc "<<count<<": ";
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
    }
}
main(){
	int n;
	cin>>n;
	int arr[n];
	int count=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	selectionSort(arr,n,count);
return 0;
}

