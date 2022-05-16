#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string str;
		cin>>str;
		cout<<n<<" ";
		int check=1;
		for(int i=str.length()-1;i>0;i--){
			if(str[i-1]<str[i]){
				for(int j=str.length()-1;j>=i;j--){
					if(str[j]>str[i-1]){
						swap(str[j],str[i-1]);
						break;
					}
				}
				int l=i,r=str.length()-1;
				while(l<r){
					swap(str[l],str[r]);
					l++;
					r--;
				}
				for(int i=0;i<str.length();i++){
					cout<<str[i];
				}
				cout<<endl;
				check=0;
				break;
			}
		}	  
		if(check==1){
			cout<<"BIGGEST"<<"\n";
		} 
	}
return 0;
}

