#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		long long a[n],b[n];
		for(long i=0;i<n;i++){
			cin>>a[i];
		}	   
		for(long i=0;i<n;i++){
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		long long result=0;
		for(long i=0;i<n;i++){
			result+=a[i]*b[n-i-1];
		}
		cout<<result<<"\n";
	}
return 0;
}

