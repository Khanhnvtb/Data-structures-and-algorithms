#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t --) {
        long long n, pos = 0,i=0;
        long long k, sum;
        cin >> n >> k;
        long a[n];
        for (long long i = 0; i < n; i ++) {
            cin >> a[i];
        }
        sum=a[0];
        int check = 0;
        while(i<n){
            if(sum==k){
                check=1;
                break;
            }else if (sum > k) {
                sum -= a[pos];
                pos ++;
                if(pos>i){
                    i=pos;
                    sum=a[i];
                }
            }else if (sum < k) {
                i++;
                sum+=a[i];
            }
        }
        if (check==1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}