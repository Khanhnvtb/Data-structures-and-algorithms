#include<bits/stdc++.h>
using namespace std;
long find(int n, long long k) {
        if (k==pow(2,n-1)){
            return n;
        }
        if (k>pow(2,n-1)){
            return find(n - 1,k-pow(2,n-1));
        }
        return find(n-1,k);
    }
main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    long long k;
	    cin>>n>>k;
	    cout<<find(n,k);
	    cout<<endl;
	}
return 0;
}

