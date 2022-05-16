#include<bits/stdc++.h>
using namespace std;
int a[20];
int n,dem=0;
bool ktra(int x,int y){
    for(int i = 1; i < x ;i++)
        if(a[i]==y||abs(i-x)==abs(a[i]-y))
            return false;
    return true;
}
void Try(int i,int n){
    for(int j = 1;j<=n;j++){
        if(ktra(i,j)){
            a[i] = j;
            if(i==n) dem++;
            Try(i+1,n);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
    	cin>>n;
    	dem=0;
   		Try(1,n);
   		cout<<dem<<"\n";
   	}
    return 0;
}
 
