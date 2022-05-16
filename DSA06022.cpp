#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
	    long n;
	    cin>>n;
	    long a[n];
	    for(long i=0;i<n;i++){
	   		cin>>a[i];
	    }
	    sort(a,a+n);
	    if(a[0]==a[n-1]){
	    	cout<<"-1"<<"\n";
		}else{
			for(int i=0;i<n-1;i++){
				if(a[i]!=a[i+1]){
					cout<<a[i]<<" "<<a[i+1]<<"\n";
					break;
				}
			}
		}
	}
return 0;
}

