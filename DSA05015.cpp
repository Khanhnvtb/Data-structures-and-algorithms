//
// Created by khanh on 5/19/2021.
//

#include <bits/stdc++.h>
using namespace std;
long m=1e9+7;
long a[1005], res;
int n,k;
void init(){
	cin>>n>>k;
}
void solve(){
	if(k>n){
        res=0;
	}else{
        res=1;
        for(int i=n-k+1;i<=n;i++){
  	        res*=i;
            res%=m;
        }
    }
	cout<<res<<"\n";
}
int main(){
    int t;
    cin>>t;
    a[0]=1;
    while(t--){
		init();
		solve();        
    }
    return 0;
}
