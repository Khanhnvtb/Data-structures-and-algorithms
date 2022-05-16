#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long n,m;
		cin>>n>>m;
		long a[n],b[m];
		long c[m+n];
		long k=0;
		for(long i=0;i<n;i++){
			cin>>a[i];
			c[k]=a[i];
			k++;
		}	   
		for(long i=0;i<m;i++){
			cin>>b[i];
			c[k]=b[i];
			k++;
		}
		sort(c,c+k);
		for(long i=0;i<k;i++){
			cout<<c[i]<<" ";
		}
		cout<<endl;
	}
return 0;
}

