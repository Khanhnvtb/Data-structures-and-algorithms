#include<bits/stdc++.h>
using namespace std;
void in(int a[], int n){
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	cout<<" ";
}
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int count=1;
		int result=0;
		for(int i=1;i<=n;i++){
			result+=pow(2,i);
		}
		cout<<result<<"\n";
		while(count<=n){
			for(int i=0;i<count;i++){
				a[i]=6;
			}	   
			in(a,count);
			int i;
			for(i=count-1;i>=0;i--){
				if(a[i]==6){
					a[i]=8;
					for(int j=i+1;j<count;j++){
						a[j]=6;
					}
					in(a,count);
					i=count;
				}
			}
			count++;
		}
		cout<<endl;
	}
return 0;
}
