#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int check=0;
		int a[k+1];
		for(int i=1;i<=k;i++){
			cin>>a[i];
		}   
		for(int i=k;i>0;i--){
			if(a[i]>a[i-1]+1){
				a[i]--;
				check=1;
				break;
			}
		}
		if(check==0){
			if(a[1]==1){
				for(int i=1;i<=k;i++){
					cout<<n-k+i<<" ";
				}
				cout<<endl;
			}else{
				a[1]--;
				cout<<a[1]<<" ";
				for(int i=2;i<=k;i++){
					cout<<n-k+i<<" ";
				}
				cout<<endl;
			}
		}else{
			for(int i=1;i<=k;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
	}
return 0;
}

