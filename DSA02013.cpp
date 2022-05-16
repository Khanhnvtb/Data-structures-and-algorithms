#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int n,p,s;
int kq=0;
vector<int>result;
bool isPrime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
void Try(int i,int dem,int sum,vector<int>b){
	if(a[i]>p){
		for(int j=1;j>=0;j--){
			if(j==1){
				sum+=a[i];
				dem++;
				b.push_back(a[i]);
				if(sum==s && dem==n){
					kq++;
					for(int h=0;h<b.size();h++){
						result.push_back(b[h]);		
					}
					return;
				}else if(sum<s){
					if(i+1<a.size()){
						Try(i+1,dem,sum,b);
					}
				}else{
					return;
				}
				sum-=a[i];
				dem--;
				b.pop_back();
			}else{
				Try(i+1,dem,sum,b);
			}
		}
	}else{
		Try(i+1,dem,sum,b);
	}
}
main(){
	int t;
	cin>>t;
	for(int i=2;i<=200;i++){
		if(isPrime(i)){
			a.push_back(i);
		}
	}
	while(t--){
	   	cin>>n>>p>>s;
	   	int dem=0,sum=0;
	   	vector<int>b;
	   	result.clear();
	   	Try(0,dem,sum,b);
//	   	cout<<result.size()/n<<"\n";
		cout<<kq<<"\n";
	   	dem=0;
	   	for(int i=0;i<result.size();i++){
	   		dem++;
			if(dem<n){
				cout<<result[i]<<" ";
			}else{
				cout<<result[i]<<"\n";
				dem=0;
			}	
		}
		kq=0;
	}
return 0;
}

