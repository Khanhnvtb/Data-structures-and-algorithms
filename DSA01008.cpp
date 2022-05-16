//#include <bits/stdc++.h>
//using namespace std;  
//void in(int a[], int n){ 
//	for(int i=1 ; i<=n ; i++){ 
//		cout<<a[i]; 
//	} 
//	cout<<endl; 
//}
//int main() { 
//	int t; 
//	cin>>t; 
//	while(t--){ 
//		int n,k; 
//		cin>>n>>k;
//		int a[n+1]; 
//		for(int i=1 ; i<=n ; i++) 
//			a[i] = 0; 
//		int b = n; 
//		int c =0; 
//		while(b!=0){ 
//			if(a[b] == 0){ 
//				a[b] = 1; 
//				c++; 
//				b = n; 
//				if(c == k){ 
//				in(a,n);
//				} 
//			}else{ 
//				c--; 
//				a[b] = 0; 
//				b--; 
//			} 
//		} 
//	} 
//	return 0; 
//}
#include<bits/stdc++.h>
using namespace std;
void in(int a[], int n){
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	cout<<"\n";
}
main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n-k;i++){
			a[i]=0;
		}
		for(int i=n-k;i<n;i++){
			a[i]=1;
		}
		in(a,n);
		for(int i=n-1;i>=0;i--){
			if(a[i]==0 && i!=n-1){
				a[i]=1;
				a[i+1]=0;
				in(a,n);
				i=n;
			}else if(a[i]==0 && i==n-1){
				int count=0;int h,check=0;
				for(int j=n-1;j>=0;j--){
					if(a[j]==0){
						count++;
					}else{
						if(count==n-k){
							check=1;
						}else{
							h=j;
							break;
						}
					}
				}
				if(check==0){
					for(int j=h;j>=0;j--){
						if(a[j]==0){
							a[j]=1;
							count++;
							h=j;
							break;
						}
					}
					for(int j=h+1;j<=h+count;j++){
						a[j]=0;
					}
					for(int j=h+count+1;j<n;j++){
						a[j]=1;
					}
					in(a,n);
					i=n;
				}else{
					break;
				}
			}
		}
	}
	return 0;
}
