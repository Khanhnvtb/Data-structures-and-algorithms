#include<bits/stdc++.h>
using namespace std;
int n;
int a[100][100];
bool check;
void Try(int i, int j, string str){
	if(i == n-1 && j == n-1){
		check = true;
		cout <<str<< " ";
	}
	if(i+1<n && a[i+1][j]==1) Try(i+1,j,str+"D");
	if(j+1<n && a[i][j+1]==1) Try(i,j+1,str+"R");
}
int main(){
	int t; 
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i< n; i++){
			for(int j = 0; j< n; j++){
				cin>>a[i][j];
			}
		}if(a[0][0] !=1 || a[n-1][n-1]!=1){
		    cout<<-1<<endl;
		}else{
		    string str ="";
		    check = false;
		    Try(0,0,str);
		    if(!check){
			     cout<<"-1"<<"\n";
		    }
            cout << endl;
		}
	}
	return 0;
}
