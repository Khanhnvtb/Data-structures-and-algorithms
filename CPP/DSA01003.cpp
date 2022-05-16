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
		int k=-1;
		for(int i=n-1;i>=0;i--){
			if(a[i]>a[i-1]){
				k=i-1;
				for(int j=n-1;j>=k;j--){
					if(a[j]>a[k]){
						int tg=a[j];
						a[j]=a[k];
						a[k]=tg;
						break;
					}
				}
				int l=k+1;
				int r=n-1;
				while(l<r){
					int tg=a[l];
					a[l]=a[r];
					a[r]=tg;
					l++;
					r--;
				}
				break;
			}
		}
		if(k==-1){
			for(int i=0;i<n;i++){
				cout<<i+1<<" ";
			}
			cout<<endl;
		}else{
			for(int i=0;i<n;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
	}
return 0;
}

