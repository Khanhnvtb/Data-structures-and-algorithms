#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		vector<int>b;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]!=0){
				b.push_back(a[i]);
			}
		}	 
		sort(b.begin(),b.end());
		long x=0,y=0;
		long result;
		for(int i=0;i<b.size();i++){
			if(i%2==0){
				x=x*10+b[i];
			}else{
				y=y*10+b[i];
			}
		}
		result=x+y;
		cout<<result<<"\n";
	}
return 0;
}

