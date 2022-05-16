#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		string str1;
		cin>>str1;
		string str2;
		cin>>str2;
		long a=0;
		long b=0;
		for(int i=str1.length()-1;i>=0;i--){
			a+=(str1[i]-48)*pow(2,str1.length()-i-1);
		}  
		for(int i=str2.length()-1;i>=0;i--){
			b+=(str2[i]-48)*pow(2,str2.length()-i-1);
		} 
		long long result=a*b;
		cout<<result<<"\n";
	}
return 0;
}

