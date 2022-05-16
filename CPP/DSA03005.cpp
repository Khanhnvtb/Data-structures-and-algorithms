#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}	   
		sort(a,a+n);
		int min=fmin(k,n-k);
		int result=0;
		for(int i=0;i<n;i++){
			if(i<min){
				result-=a[i];
			}else{
				result+=a[i];
			}
		}
		cout<<result<<"\n";
	}
return 0;
}

