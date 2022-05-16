#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool used[10]={false};
		vector<int>a;
		while(n--){
			string str;
			cin>>str;
			for(int i=0;i<str.length();i++){
				if(a.size()>=10){
					break;
				}else{
					if(used[(int)(str[i]-'0')]==false){
						a.push_back((int)(str[i]-'0'));
						used[(int)(str[i]-'0')]=true;
					}
				}
			}
		}	   
		sort(a.begin(),a.end());
		for(int i=0;i<a.size();i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
return 0;
}

