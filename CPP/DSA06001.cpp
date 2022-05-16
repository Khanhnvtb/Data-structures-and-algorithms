#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}	   
		sort(a,a+n);
		for(int i=0;i<n;i++){
			if(i%2==0){
				cout<<a[n-1-i/2]<<" ";
			}else{
				cout<<a[i/2]<<" ";
			}
		}
		cout<<endl;
	}
return 0;
}

