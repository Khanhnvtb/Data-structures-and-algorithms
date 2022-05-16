#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		char s[n];
		for(int j=0;j<n;j++){
			s[j]='A';
		}	
		for(int j=0;j<n;j++){
			cout<<s[j];
		}
		cout<<" ";
		int i;   
		for(i=n-1;i>=0;i--){
			if(s[i]=='A'){
				s[i]='B';
				for(int j=i+1;j<n;j++){
					s[j]='A';
				}
				for(int j=0;j<n;j++){
					cout<<s[j];
				}
				cout<<" ";
				i=n;
			}
		}
		cout<<endl;
	}
return 0;
}

