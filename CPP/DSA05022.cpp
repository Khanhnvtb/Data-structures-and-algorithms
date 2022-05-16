//
// Created by khanh on 5/30/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, ins, del, cop, res[105];
void init() {
    cin >> n >> ins >> del >> cop;
}
void solve() {
    res[0] = 0;
    res[1] = ins;
    for (int i = 2; i <= n; i ++) {
        if (i % 2 == 0) {
            res[i] = min(res[i - 1] + ins, res[i / 2] + cop);
        } else {
            res[i] = min(res[i - 1] + ins, res[(i + 1) / 2] + cop + del);
        }
    }
}
void print() {
    cout << res[n] << "\n";
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