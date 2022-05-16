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
		int check=1;
		int min1=a[n/2];
		int max1=a[n/2];
		int min2,max2;
		for(int i=n/2-1;i>=0;i--){
			min2=fmin(a[i],a[n-i-1]);
			max2=fmax(a[i],a[n-i-1]);
			if(min2>=min1 || max2<=max1){
				check=0;
				break;
			}else{
				min1=min2;
				max1=max2;
			}
		}
		if(check==1){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
return 0;
}
