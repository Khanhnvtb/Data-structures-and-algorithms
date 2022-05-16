#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		int a[n],b[n];
		for(long long i=0;i<n;i++){
			cin>>a[i];
		}
		for(long long i=0;i<n;i++){
			cin>>b[i];
		}
		for(long long i=0;i<n-1;i++){
			for(long long j=i+1;j<n;j++){
				if(b[i]>b[j]) {
                    swap (a[i], a[j]);
                    swap (b[i],b[j]);
                }
			}
		}
		long long dem=1;
		long long k=0;
		for(long long i=1;i<n;i++){
			if(a[i]>=b[k]){
				dem++;
				k=i;
			}
		}
		cout<<dem<<"\n";
	}
return 0;
}


