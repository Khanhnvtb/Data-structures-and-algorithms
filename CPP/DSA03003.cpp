#include<bits/stdc++.h>
using namespace std;
long m=1e9+7;
main(){
	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		long a[n];
		for(long i=0;i<n;i++){
			cin>>a[i];
		}	   
		sort(a,a+n);
		long result=0;
		for(long i=1;i<n;i++){
			result=(result%m+a[i]*i%m)%m;
		}
		cout<<result%m<<"\n";
	}
return 0;
}

