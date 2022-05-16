#include<bits/stdc++.h>
using namespace std;
void in(int a[], int n){
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	cout<<" ";
}
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		n++;
		while(n--){
			for(int i=0;i<n;i++){
				a[i]=8;
			}	   
			in(a,n);
			int i;
			for(i=n-1;i>=0;i--){
				if(a[i]==8){
					a[i]=6;
					for(int j=i+1;j<n;j++){
						a[j]=8;
					}
					in(a,n);
					i=n;
				}
			}
		}
		cout<<endl;			
	}
return 0;
}

