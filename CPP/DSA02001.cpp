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
		cout<<"["<<a[0];
		for(int i=1;i<n;i++){
			cout<<" "<<a[i];
		}
		cout<<"]"<<"\n";
		while(n>1){
			cout<<"[";
			a[0]=a[0]+a[1];
			cout<<a[0];
			for(int i=1;i<n-1;i++){
				a[i]=a[i]+a[i+1];
				cout<<" "<<a[i];
			}
			cout<<"]"<<"\n";
			n--;
		}
		cout<<endl;
	}
return 0;
}

