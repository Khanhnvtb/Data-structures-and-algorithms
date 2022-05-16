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
		long l=0;
		while(a[l]<=a[l+1] && l<n-1) l++;
		long r=n-1;
		while(a[r]>=a[r-1] && r>0) r--;
		long min=a[l],max=a[l];
		for(long i=l+1;i<=r;i++){
			if(a[i]<min){
				min=a[i];
			}
			if(a[i]>max){
				max=a[i];
			}
		}
		for(long i=0;i<=l;i++){
			if(a[i]>min){
				l=i+1;
				break;
			}
		}
		for(long i=n-1;i>=r;i--){
			if(a[i]<max){
				r=i+1;
				break;
			}
		}
		cout<<l<<" "<<r<<"\n";
	}
return 0;
}

