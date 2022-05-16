#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[k+1];
		int count=0;
		int check=1;
		for(int i=1;i<=k;i++){
			cin>>a[i];
		}	   
		vector<int>b;
		for(int i=k;i>0;i--){
			if(a[i]!=n-k+i){
				a[i]++;
				count=k-i+1;
				for(int j=i+1;j<=k;j++){
					b.push_back(a[i]+j-i);
				}
				check=i+1;
				break;
			}
		}
		if(check==1){
			cout<<k<<"\n";
		}else{
			int h=0;
			for(int i=check;i<=k;i++){
				for(int j=h;j<b.size();j++){
					if(a[i]==b[j]){
						count--;
						h=j+1;
						break;
					}else if(a[i]<b[j]){
						h=j;
						break;
					}
				}
			}
			cout<<count<<"\n";
		}
	}
return 0;
}

