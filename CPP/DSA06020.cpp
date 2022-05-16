#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long n,x;
		cin>>n>>x;
		long a[n];
		int check=-1;
		for(long i=0;i<n;i++){
			cin>>a[i];
			if(check!=1){
				if(a[i]==x){
					check=1;
				}
			}
		}	   
		cout<<check<<"\n";
	}
return 0;
}

