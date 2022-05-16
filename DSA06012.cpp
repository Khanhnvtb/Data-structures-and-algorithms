#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		long a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}	   
		sort(a,a+n);
		int i=n-1;
		while(k--){
			cout<<a[i]<<" ";
			i--;
		}
		cout<<endl;
	}
return 0;
}

