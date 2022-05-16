#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		long max=0;
		for(long i=0;i<str.length()-max/2-1;i++){
			if(str[i]=='(' && str[i+1]==')'){
				long count=2;
				for(long j=i-1;j>=0;j--){
					if(str[j]=='(' && str[i+i-j]==')'){
						count+=2;
					}else{
						break;
					}
				}
				if(count>max){
					max=count;
				}
			}
		}	   
		cout<<max<<"\n";
	}
return 0;
}

