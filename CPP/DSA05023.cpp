//
// Created by khanh on 5/19/2021.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        long long res=0;
        long long tmp;
        for(int i=0;i<str.length();i++){
            for(int j=0;j<str.length()-i;j++){
                tmp=0;
                for(int k=j;k<=j+i;k++){
                    tmp=tmp*10+(str[k]-48);
                }
                res+=tmp;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}