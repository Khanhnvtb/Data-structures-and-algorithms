#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[n],b[m];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}	   
		for(int i=0;i<m;i++){
			cin>>b[i];
		}
		int result[m+n-1]={0};
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				result[i+j]+=a[i]*b[j];
			}
		}
		for(int i=0;i<m+n-1;i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
	}
return 0;
}

