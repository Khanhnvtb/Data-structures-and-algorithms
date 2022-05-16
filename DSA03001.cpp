#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		int a[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
		int count=0,i=9;
		while(n>0){
			if(n>=a[i]){
				count+=n/a[i];
				n=n%a[i];
			}else{
				i--;
			}
		} 
		cout<<count<<"\n";
	}
return 0;
}

