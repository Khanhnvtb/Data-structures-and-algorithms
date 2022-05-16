#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long n,x;
		cin>>n>>x;
		long a[n];
		long result;
		for(long i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==x){
				result=i+1;
			}
		}	   
		cout<<result<<"\n";
	}
return 0;
}

