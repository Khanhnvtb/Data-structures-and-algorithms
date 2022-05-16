#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int m,s;
		cin>>m>>s;
		if(m/9>s){
			cout<<"-1"<<"\n";
		}else if(m/9 == s){
			if(m%9==0){
				for(int i=1;i<=s;i++){
					cout<<"9";
				}
				cout<<endl;
			}else{
				cout<<"-1"<<"\n";
			}
		}else if(m/9<s && m!=0){
			if(m%9==0){
				cout<<"1";
				for(int i=1;i<s-m/9;i++){
					cout<<"0";
				}
				cout<<"8";
				for(int i=1;i<m/9;i++){
					cout<<"9";
				}
				cout<<endl;
			}else{
				if(s-m/9==1){
					cout<<m%9;
					for(int i=0;i<m/9;i++){
						cout<<"9";
					}
					cout<<endl;
				}else{
					cout<<"1";
					for(int i=1;i<s-m/9-1;i++){
						cout<<"0";
					}
					cout<<m%9-1;
					for(int i=1;i<=m/9;i++){
						cout<<"9";
					}
					cout<<endl;
				}
			}
		}else if(m==0 && m/9<s){
			cout<<"0"<<"\n";
		}	   
	}
return 0;
}

