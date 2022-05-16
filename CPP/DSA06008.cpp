#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long n,m;
		cin>>n>>m;
		int a[n],b[m];
		for(long i=0;i<n;i++){
			cin>>a[i];
		}	   
		for(long i=0;i<m;i++){
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		long result=0;
		long dem0=0,dem1=0,h=0;
		for(long i=0;i<m;i++){
			if(b[i]==0){
				dem0++;
			}else if(b[i]==1){
				dem1++;
			}else if(b[i]>1){
				break;
			}
		}
		for(long i=0;i<n;i++){
			if(a[i]==1){
				result+=dem0;
			}else if(a[i]==2){
				result+=dem0;
				result+=dem1;
				for(long j=0;j<m;j++){
					if(b[j]>4){
						result+=m-j;
						break;
					}
				}
			}else if(a[i]==3){
				result+=dem0;
				result+=dem1;
				for(long j=0;j<m;j++){
					if(b[j]==2){
						result++;
					}else if(b[j]>3){
						result+=m-j;
						break;
					}
				}
			}else if(a[i]>3){
				result+=dem0;
				result+=dem1;
				for(long j=h;j<m;j++){
					if(b[j]>a[i]){
						result+=m-j;
						h=j;
						break;
					}
				}
			}
		}
		cout<<result<<"\n";
	}
return 0;
}

