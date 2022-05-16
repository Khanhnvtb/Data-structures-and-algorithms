#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		long long p,q;
		cin>>p>>q;
		while(1){
			if(q%p==0){
				cout<<"1/"<<q/p;
				break;
			}else{
				long long n=q/p+1;
				cout<<"1/"<<n<<" + ";
				p=p*n-q;
				q*=n;
			}
		}	   
		cout<<endl;
	}
return 0;
}

