#include<bits/stdc++.h>
using namespace std;
long m=1e9+7;
long dao(long n){
	long result=0;
	while(n>0){
		result=result*10+n%10;
		n/=10;
	}
	return result;
}
long power(long x,long y) 
{ 	if(y==0){
		return 1;
	}else if(y==1){
		return x;
	}else{
    	if(y%2==0){
    		return (power(x,y/2)%m*power(x,y/2)%m)%m;
		}else{
			return (power(x,y/2)%m*power(x,y/2)%m*x%m)%m;
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
	    long n;
	    cin>>n;
	    long r=dao(n);
	    long result=power(r,n);
	    cout<<result<<"\n";
	}
return 0;
}

