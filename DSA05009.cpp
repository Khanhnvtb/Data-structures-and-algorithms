//
// Created by khanh on 10/04/2021.
//
#include<bits/stdc++.h>
using namespace std;
int check;
int a[101],sum,n;
void Try(int i, int s, int sumbest){
    if(check==1){
        return;
    }
    for(int j=1;j>=0;j--){
        if(j==1){
            s+=a[i];
            sumbest-=a[i];
            if(s==sum/2){
                check=1;
                return;
            }else if(s>sum/2 || sumbest <sum/2 ){
                return;
            }else{
                if(i>0){
                    Try(i-1,s,sumbest);
                }
            }
            s-=a[i];
            sumbest+=a[i];
        }else{
            if(i>0){
                Try(i-1,s,sumbest);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2==1){
            cout<<"NO"<<"\n";
        }else {
            sort(a, a + n);
            int sumbest = sum;
            check = 0;
            Try(n - 1,0, sumbest);
            if (check == 1) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
    return 0;
}
