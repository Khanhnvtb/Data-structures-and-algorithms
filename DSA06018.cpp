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
		int count=0;
		sort(a,a+n);
		int result=a[n-1]-a[0]+1;
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1]){
				count++;
			}
		}
		result=result-n+count;
		cout<<result<<"\n";
	}
return 0;
}

