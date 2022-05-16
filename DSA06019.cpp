#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}	   
		sort(a,a+n);
		vector<long>b;
		vector<int>c;
		b.push_back(a[0]);
		c.push_back(1);
		for(int i=1;i<n;i++){
			if(a[i]!=a[i-1]){
				b.push_back(a[i]);
				c.push_back(1);
			}else{
				c[c.size()-1]++;
			}
		}
		for(int i=0;i<c.size()-1;i++){
			for(int j=i+1;j<c.size();j++){
				if(c[i]<c[j]){
					int tg=c[i];
					c[i]=c[j];
					c[j]=tg;
					long tg2=b[i];
					b[i]=b[j];
					b[j]=tg2;
				}else if(c[i]==c[j] && b[i]>b[j]){
					int tg=b[i];
					b[i]=b[j];
					b[j]=tg;
				}
			}
		}
		for(int i=0;i<b.size();i++){
			while(c[i]--){
				cout<<b[i]<<" ";
			}
		}
		cout<<endl;
	}
return 0;
}

