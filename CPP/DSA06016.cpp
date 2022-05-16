#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long n,m;
		cin>>n>>m;
		long a[n],b[m];
		for(long i=0;i<n;i++){
			cin>>a[i];
		}	   
		for(long i=0;i<m;i++){
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+m);
		long long result=a[n-1]*b[0];
		cout<<result<<"\n";
	}
return 0;
}

