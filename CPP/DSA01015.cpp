#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	vector<long long>b;
	int a[18]={0};
	for(int i=17;i>=0;i--){
		if(a[i]==0){
			a[i]=9;
			for(int j=i+1;j<18;j++){
				a[j]=0;
			}
			long long x=0;
			for(int j=0;j<18;j++){
				x=x*10+a[j];
			}
			b.push_back(x);
			i=18;
		}
	}
	while(t--){
	    int n;
	    cin>>n;
	    for(int i=0;i<b.size();i++){
	    	if(b[i]%n==0){
	    		cout<<b[i]<<"\n";
	    		break;
			}
		}
	}
return 0;
}

