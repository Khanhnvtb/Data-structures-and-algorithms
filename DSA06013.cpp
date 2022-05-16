#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		long a[n];
		int count=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==x){
				count++;
			}
		}	   
		if(count==0){
			cout<<"-1"<<"\n";
		}else{
			cout<<count<<"\n";
		}
	}
return 0;
}

