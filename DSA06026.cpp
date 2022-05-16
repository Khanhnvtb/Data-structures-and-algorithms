#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b){
	int tg=a;
	a=b;
	b=tg;
}
void in(int a[], int n, int count){
	cout<<"Buoc "<<count<<": ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void bubbleSort(int a[], int n, int count){
	bool check=false;
	for(int i=0;i<n-1;i++){
		if(count>0){
			in(a,n,count);
		}
		check=false;
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				check=true;		
			}
		}
		count++;
		if(check==false){
			break;
		}
	}
}
main(){
	int n;
	cin>>n;
	int count=0;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bubbleSort(a,n,count);
return 0;
}

