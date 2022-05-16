#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long n,m,k;
		cin>>n>>m>>k;
		long a[n],b[m];
		vector<long>c;
		for(int i=0;i<n;i++){
			cin>>a[i];
			c.push_back(a[i]);
		}	   
		for(long i=0;i<m;i++){
			cin>>b[i];
			c.push_back(b[i]);
		}
		sort(c.begin(),c.end());
		cout<<c[k-1]<<"\n";
	}
return 0;
}

