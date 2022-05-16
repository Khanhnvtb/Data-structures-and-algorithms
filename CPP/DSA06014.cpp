#include<bits/stdc++.h>
using namespace std;
bool isPrime(long n){
	if(n<2){
		return false;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
main(){
	int t;
	cin>>t;
	while(t--){
	    long n;
	    cin>>n;
	    int check=-1;
	    for(long i=2;i<=sqrt(n);i++){
	   		if(isPrime(i) && isPrime(n-i)){
	   			check=1;
	   			cout<<i<<" "<<n-i<<"\n";
	   			break;
			}
	    }
	   	if(check==-1){
	   		cout<<check<<"\n";
	   	}
	}
return 0;
}

