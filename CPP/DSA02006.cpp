#include<bits/stdc++.h>
using namespace std;
int n,k,a[20];
bool check=false;
void Try(int i,int sum,vector<int>result){
	for(int j=1;j>=0;j--){
		sum+=a[i]*j;
		if(j==1){
			result.push_back(a[i]);
			if(sum==k){
				check=true;
				result.push_back(a[i]);
				cout<<"[";
				for(int h=0;h<result.size()-2;h++){
					cout<<result[h]<<" ";
				}
				cout<<result[result.size()-2]<<"] ";
				return;
			}else if(sum>k){
				return;
			}else{
				if(i<n) Try(i+1,sum,result);
			}
			sum-=a[i];
			result.pop_back();
		}else{
			if(i<n) Try(i+1,sum,result);
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int sum=0;
		check=false;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}	
		sort(a,a+n);  
		vector<int>result; 
		Try(0,sum,result);
		if(check==false){
			cout<<"-1";
		}
		cout<<endl;
	}
return 0;
}
