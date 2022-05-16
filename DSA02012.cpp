#include<bits/stdc++.h>
using namespace std;
int count(int m,int n){
	if(m==1 || n==1){
		return 1;
	}else{
		return count(m-1,n)+count(m,n-1);
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		int a[m][n];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		cout<<count(m,n)<<"\n";
	}
return 0;
}

