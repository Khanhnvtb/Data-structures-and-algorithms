#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,s,m;
		cin>>n>>s>>m;
		int x=s*m;
		int sum=0;
		int result=0;
		for(int i=1;i<=s;i++){
			if(i%7!=0){
				sum+=n;
			}else{
				result--;
			}
			if(sum>=x){
				cout<<result+i<<"\n";
				break;
			}
		}
		if(sum<x){
			cout<<"-1"<<"\n";
		}
	}
return 0;
}

