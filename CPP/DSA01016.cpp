#include<bits/stdc++.h>
using namespace std;
void in(int a[], int k){
	cout<<"(";
	for(int i=0;i<k-1;i++){
		cout<<a[i]<<" ";
	}
	cout<<a[k-1]<<")"<<" ";
}
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[20];
		a[0]=n;
		int k=1;
		in(a,k);
		int sum=0;
		for(int i=k-1;i>=0;i--){
			if(a[i]!=1){
				a[i]--;
				sum++;
				int x=sum/a[i];
				for(int j=i+1;j<=i+x;j++){
					a[j]=a[i];
				}
				k=i+x+1;
				if(sum%a[i]!=0){
					a[k]=sum%a[i];
					k++;
				}
				in(a,k);
				sum=0;
				i=k;
			}else{
				sum++;
			}
		}
		cout<<endl;
	}
return 0;
}

