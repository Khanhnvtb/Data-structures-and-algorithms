#include<bits/stdc++.h>
using namespace std;
long n,k;
void find(long x, long y, long a[]){
	long z=(x+y)/2;
	if(a[z]==k){
		cout<<z<<"\n";
		return;
	}else if(a[z]>k){
		if(a[z-1]<k){
			cout<<"NO"<<"\n";
			return;
		}else if(a[z-1]==k){
			cout<<z-1<<"\n";
			return;
		}else{
			find(x,z-1,a);
		}
	}else{
		if(a[z+1]==k){
			cout<<z+1<<"\n";
			return;
		}else if(a[z+1]>k){
			cout<<"NO"<<"\n";
			return;
		}else{
			find(z+1,y,a);
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		long a[n+1];
		for(long i=1;i<=n;i++){
			cin>>a[i];
		}	   
		if(a[n]<k || a[1]>k){
			cout<<"NO"<<"\n";
		}else{
			find(1,n,a);
		}
	}
return 0;
}

