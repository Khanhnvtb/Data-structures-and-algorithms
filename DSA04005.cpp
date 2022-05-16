#include <bits/stdc++.h>
using namespace std;
string in(int n, long long k, long long a[])
{
    if(n==1){
        return "A";
    }
    if(n==2){
        return "B";
    }
    if(k<=a[n-2]){
        return in(n-2,k,a);
	}else{
    	return in(n-1,k-a[n-2],a);
    }
}
int main()
{	
    int t;
    cin>>t;
    while (t--){	
		int n;
   	 	long long k;
        cin>>n>>k;
        long long a[100];
        a[0]=0;
		a[1]=1;
		for(int i=2;i<93;i++){
			a[i]=a[i-1]+a[i-2];
		}
        cout<<in(n,k,a)<<endl;
    }
    return 0;
}
