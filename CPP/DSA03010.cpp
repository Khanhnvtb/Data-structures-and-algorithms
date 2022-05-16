#include <bits/stdc++.h>
using namespace std;
long n;
main(){
	int t;
    cin>>t;
    while(t--){
        cin>>n;
        priority_queue<long long, vector<long long>, greater<long long> >a;
    	for(int i=0;i<n;i++){
    		long k;
       	 	cin>>k;
        	a.push(k);
    	}
        long result=0;
    	while(a.size()>1){
        	long x=a.top();
        	a.pop();
       		long y=a.top();
        	a.pop();
        	long long z=x+y;
        	a.push(z);
        	result+=z;
    	}
    	cout<<result<<endl;
	}
    return 0;
}
