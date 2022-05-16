//
// Created by khanh on 5/30/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, k;
long m=1e9+7, a[1005], res[1005];
void init() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    memset(res, 0, sizeof(res));
    res[0] = 1;
    for (int i = 1; i <= k; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i >= a[j]) {
                res[i] = (res[i] + res[i - a[j]]) % m;
            }
        }
    }
}
void print() {
    cout << res[k] << "\n";
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        init();
        solve();
        print();
    }
    return 0;
}