#include<bits/stdc++.h>
using namespace std;
long long a[100];
void khoitao(){
	a[0]=0;
	a[1]=1;
	for(int i=2;i<93;i++){
		a[i]=a[i-1]+a[i-2];
	}
}
int find(int n, long long k){
	if(n==1){
		return 0;
	}else if(n==2){
		return 1;
	}else{
		if(k<=a[n-2]){
			return find(n-2,k); 
		}else{
			return find(n-1,k-a[n-2]);
		}
	}
}
main(){
	int t;
	cin>>t;
	khoitao();
	while(t--){
	    int n;
	    cin>>n;
	    long long k;
	    cin>>k;
	    cout<<find(n,k)<<"\n";
	}
return 0;
}

