#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long n,x;
		cin>>n>>x;
		long a[n];
		for(long i=0;i<n;i++){
			cin>>a[i];
		}	   
		for(long i=0;i<n-1;i++){
			for(long j=0;j<n-i-1;j++){
				if(abs(x-a[j])>abs(x-a[j+1])){
					long tg=a[j];
					a[j]=a[j+1];
					a[j+1]=tg;
				}
			}
		}
		for(long i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
return 0;
}

