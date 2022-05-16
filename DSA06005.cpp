#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long n,m;
		cin>>n>>m;
		long a[n],b[m];
		vector<long>c;
		for(long i=0;i<n;i++){
			cin>>a[i];
			c.push_back(a[i]);
		}
		sort(a,a+n);
		for(long i=0;i<m;i++){
			cin>>b[i];
			c.push_back(b[i]);
		}
		sort(b,b+m);
		sort(c.begin(),c.end());
		cout<<c[0]<<" ";
		for(long i=1;i<c.size();i++){
			if(c[i]!=c[i-1]){
				cout<<c[i]<<" ";
			}
		}
		cout<<endl;
		long h=0;
		vector<long>d;
		for(long i=0;i<n;i++){
			for(long j=h;j<m;j++){
				if(a[i]==b[j]){
					d.push_back(a[i]);
					h=j+1;
					break;
				}else if(a[i]<b[j]){
					break;	
				}
			}
		}
		for(long i=0;i<d.size();i++){
			cout<<d[i]<<" ";
		}
		cout<<endl;
	}
return 0;
}
