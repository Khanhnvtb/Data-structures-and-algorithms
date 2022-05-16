#include<bits/stdc++.h>
using namespace std;
void in(int a[], long n){
	for(long i=0;i<n;i++){
		if(a[i]!=0){
			for(long j=i;j<n;j++){
				cout<<a[j];
			}
			break;
		}
	}
	cout<<" ";
}
main(){
	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		int a[n];
		for(long i=0;i<n;i++){
			a[i]=0;
		}   
		long count=1;
		long i;
		for(i=n-1;i>=0;i--){
			if(a[i]==0){
				a[i]=1;
				for(long j=i+1;j<n;j++){
					a[j]=0;
				}
				in(a,n);
				count++;
				if(count<=n){
					i=n;
				}else{
					break;
				}
			}
		}
		cout<<endl;
	}
return 0;
}

