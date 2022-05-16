#include<bits/stdc++.h>
using namespace std;
int a[50];
int b[50]={0};
void xuat(int n){
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<" ";
}
void Try(int k,int n){
	for(int i=n;i>=1;i--){
		if(b[i]==0){
			a[k]=i;
			b[i]=1;
			if(k==n){
				xuat(n);
			}else{
				Try(k+1,n);
			}
			b[i]=0;
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Try(1,n);
		cout<<endl;
	}
}
