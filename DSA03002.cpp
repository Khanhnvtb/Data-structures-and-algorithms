#include<bits/stdc++.h>
using namespace std;
long min(long n){
	long result=0;
	int count=0;
	while(n>0){
		int x=n%10;
		if(x==6){
			x=5;
		}
		result+=x*pow(10,count);
		count++;
		n/=10;
	}
	return result;
}
long max(long n){
	long result=0;
	int count=0;
	while(n>0){
		int x=n%10;
		if(x==5){
			x=6;
		}
		result+=x*pow(10,count);
		count++;
		n/=10;
	}
	return result;
}
main(){
	long a,b;
	cin>>a>>b;
	cout<<min(a)+min(b)<<" "<<max(a)+max(b);  
return 0;
}

