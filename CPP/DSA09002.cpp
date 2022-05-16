#include<bits/stdc++.h>
using namespace std;
main(){
	int n;
	cin>>n;
	cin.ignore();
	vector<int>a;
	for(int i=1;i<=n;i++){
		string str;
		getline(cin,str);
		int x=0;
		for(int j=0;j<str.length();j++){
			if(str[j]!=' '){
				x=x*10+(int)(str[j]-'0');
			}else{
				if(x>i){
					a.push_back(i);
					a.push_back(x);
				}
				x=0;
			}
		}
		if(x>i){
			a.push_back(i);
			a.push_back(x);
		}
	}
	for(int i=0;i<a.size();i+=2){
		cout<<a[i]<<" "<<a[i+1]<<"\n";
	}
return 0;
}

