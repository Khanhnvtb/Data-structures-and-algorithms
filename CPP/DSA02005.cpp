#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int n=str.length();
		int a[n];
		for(int i=0;i<n;i++){
			a[i]=i;
			cout<<str[a[i]];
		}	
		cout<<" ";
		int i;   
		for(i=n-1;i>0;i--){
			if(a[i-1]<a[i]){
				for(int j=n-1;j>=i;j--){
					if(a[j]>a[i-1]){
						swap(a[i-1],a[j]);
						break;
					}
				}
				int l=i;
				int r=n-1;
				while(l<r){
					swap(a[l],a[r]);
					l++;
					r--;
				}
				for(int j=0;j<n;j++){
					cout<<str[a[j]];
				}
				cout<<" ";
				i=n;
			}
		}
		cout<<endl;
	}
return 0;
}

