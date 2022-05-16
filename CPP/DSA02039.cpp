//
// Created by KhanhNVTB on 09/05/2021.
//

#include<bits/stdc++.h>
using namespace std;
int cnt;
vector<int>res;
void add(int a[], int k){
    for(int i=0;i<k;i++){
        res.push_back(a[i]);
    }
    res.push_back(-1);
}
main(){
    int t;
    cin>>t;
    while(t--){
        res.clear();
        int n;
        cin>>n;
        int a[20];
        a[0]=n;
        int k=1;
        add(a,k);
        cnt=1;
        int sum=0;
        for(int i=k-1;i>=0;i--){
            if(a[i]!=1){
                a[i]--;
                sum++;
                int x=sum/a[i];
                for(int j=i+1;j<=i+x;j++){
                    a[j]=a[i];
                }
                k=i+x+1;
                if(sum%a[i]!=0){
                    a[k]=sum%a[i];
                    k++;
                }
                add(a,k);
                cnt++;
                sum=0;
                i=k;
            }else{
                sum++;
            }
        }
        res.pop_back();
        cout<<cnt<<"\n";
        cout<<"(";
        for(int i=0;i<res.size();i++){
            if(res[i]!=-1){
                if(res[i+1]==-1) {
                    cout << res[i];
                }else{
                    cout<<res[i]<<" ";
                }
            }else{
                cout<<") (";
            }
        }
        cout<<")";
        cout<<endl;
    }
    return 0;
}