#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int x=n;
		vector<int>result;
		for(int i=0;i<n;i++){
			cin>>a[i];
			result.push_back(a[i]);
		}
		while(n>0){
			for(int i=0;i<n-1;i++){
				a[i]=a[i]+a[i+1];
				result.push_back(a[i]);
			}
			n--;
		}
		int i=0,j=result.size()-1;
		while(i<x){
			cout<<"[";
			for(int k=j-i;k<j;k++){
				cout<<result[k]<<" ";
			}
			cout<<result[j]<<"]"<<" ";
			i++;
			j-=i;
		}
		cout<<endl;
	}
return 0;
}

