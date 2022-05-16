#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
	   	int E,V;
		cin>>E>>V;
		int a[V+1][3];
		for(int i=1;i<=V;i++){
			for(int j=1;j<=2;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=E;i++){
			cout<<i<<": ";
			vector<int>result;
			for(int j=1;j<=V;j++){
				if(a[j][1] == i){
					result.push_back(a[j][2]);
				}
			}
			sort(result.begin(),result.end());
			for(int i=0;i<result.size();i++){
				cout<<result[i]<<" ";
			}
			cout<<endl;
		}    
	}
return 0;
}

