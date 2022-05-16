#include<bits/stdc++.h>
using namespace std;
int n;
int a[100][100];
int check=0;
void Try(int i,int j,string str){
    if(i==n-1 && j==n-1){
        cout<<str<<" ";
        check=1;
        return;
    }
    if(a[i+1][j]==1){
        Try(i+1,j,str+="D");    
    }
    if(a[i][j+1]==1){
        Try(i,j+1,str+="R");
    }
}
main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        check=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        if(a[0][0]==0 || a[n-1][n-1]==0){
            cout<<"-1";
        }else{
            string str="";
            Try(0,0,str);
            if(check==0){
                cout<<"-1";
            }
        }
        cout<<endl;
     }
return 0;
}
