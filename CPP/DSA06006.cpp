#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		int a[n];
		for(long i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(long i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}
