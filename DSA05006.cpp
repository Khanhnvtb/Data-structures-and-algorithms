//
// Created by khanh on 5/19/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        long a[n], res[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        res[0]=a[0];
        for(int i=1;i<n;i++){
            res[i]=a[i];
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                    res[i]=max(res[i],res[j]+a[i]);
                }
            }
        }
        sort(res,res+n);
        cout<<res[n-1]<<"\n";
    }
    return 0;
}