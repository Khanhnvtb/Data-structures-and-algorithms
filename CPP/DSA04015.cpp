#include<bits/stdc++.h>
using namespace std;
long n;
long long k;
long floor(long x, long y,long long a[]){
	long z=(x+y)/2;
	if(a[z]==k){
		return z;
	}else if(a[z]<k){
		if(a[z+1]>k){
			return z;
		}else{
			return floor(z+1,y,a);
		}
	}else if(a[z]>k){
		if(a[z-1]<k){
			return z-1;
		}else{
			return floor(x,z-1,a);
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		long long a[n+1];
		for(long i=1;i<=n;i++){
			cin>>a[i]; 
		} 	   
		if(a[1]>k){
			cout<<"-1"<<"\n";
		}else{
			cout<<floor(1,n,a)<<"\n";
		}
	}
return 0;
}
