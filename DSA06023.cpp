#include<bits/stdc++.h>
using namespace std;
main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int count=0;
	for(int i=0;i<n-1;i++){
		count++;
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int tg=a[i];
				a[i]=a[j];
				a[j]=tg;
			}
		}
		cout<<"Buoc "<<count<<": ";
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
return 0;
}
