#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		int k;
		cin>>k;
		string str1;
		cin>>str1;
		string str2;
		cin>>str2;
		long long sum=0;
		int dem=0;
		for(int i=str1.length()-1;i>=0;i--){
			sum+=(str1[i]-48)*pow(k,dem);
			dem++;
		}
		dem=0;
		for(int i=str2.length()-1;i>=0;i--){
			sum+=(str2[i]-48)*pow(k,dem);
			dem++;
		}
		vector<int>res;
		while(sum>0){
			int x=sum%k;
			res.push_back(x);
			sum/=k;
		}
		for(int i=res.size()-1;i>=0;i--){
			cout<<res[i];
		}
		cout<<endl;
	}
return 0;
}

