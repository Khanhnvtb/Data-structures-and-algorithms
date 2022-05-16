#include<bits/stdc++.h>
using namespace std;
long long s;
int n;
long a[100];
int result;
bool check;
void Try(int i,long long sum,int dem,int sumbest){
    for(int j=1;j>=0;j--){
        if(j==1){
            sum+=a[i];
            sumbest-=a[i];
            dem++;
            if(sum==s){
                if(dem<result){
                    result=dem;
                    check=true;
                }
                return;
            }else if(sum>s || sumbest<s-sum || dem>=result){
                return;
            }else{
                if(i>0) Try(i-1,sum,dem,sumbest);
            }
            sum-=a[i];
            sumbest+=a[i];
            dem--;
        }else{
            if(i>0)
                Try(i-1,sum,dem,sumbest);
        }
    }
}
main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>s;
        long long sum=0;
        int dem=0;
        check=0;
        result=INT_MAX;
        int sumbest=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sumbest+=a[i];
        }
        sort(a,a+n);
        Try(n-1,sum,dem,sumbest);
        if(!check){
            cout<<"-1";
        }else{
            cout<<result<<"\n";
        }
        cout<<endl;
    }
    return 0;
}