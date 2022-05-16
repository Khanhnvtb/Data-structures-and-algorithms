#include<bits/stdc++.h>
using namespace std;
int n;
int dem(int x, int y, int a[]){
	int z=(x+y)/2;
	if(a[z]==0){
		if(a[z+1]==1){
			return z;
		}else{
			return dem(z+1,y,a);
		}
	}else{
		if(a[z-1]==0){
			return z-1;
		}else{
			return dem(x,z-1,a);
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
	  	cin>>n;
	  	int a[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		if(a[1]==1){
			cout<<0<<"\n";
		}else if(a[n]==0){
			cout<<n<<"\n";
		}else{
			cout<<dem(1,n,a)<<"\n";
		}
	}
return 0;
}

