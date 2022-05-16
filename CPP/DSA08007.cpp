#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		vector<long long>b;
		int a[18]={0};
		int i;
		for(i=17;i>=0;i--){
			if(a[i]==0){
				a[i]=1;
				for(int j=i+1;j<18;j++){
					a[j]=0;
				}
				long long x=0;
				for(int j=0;j<18;j++){
					x=x*10+a[j];
				}
				if(x>n){
					break;
				}
				b.push_back(x);
				i=18;
			}
		}
		cout<<b.size()<<"\n";
	}
return 0;
}

