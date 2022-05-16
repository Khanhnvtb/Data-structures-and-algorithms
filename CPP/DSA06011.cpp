#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}	   
		long min=LONG_MAX;
		long result;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(abs(a[i]+a[j])<min){
					min=abs(a[i]+a[j]);
					result=a[i]+a[j];
				}
			}
		}
		cout<<result<<"\n";
	}
return 0;
}

