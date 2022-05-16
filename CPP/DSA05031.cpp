//
// Created by khanh on 5/30/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, res[10005];
void init() {
    cin >> n;
}
void solve() {
    for (int i = 1; i <= 10000; i ++) {
        res[i] = i;
        for (int j = 1; j <= sqrt(i); j ++) {
            res[i] = min(res[i], res[i - j * j] + 1);
        }
    }
}
void print() {
    cout << res[n] << endl;
}
int main() {
    int t;
    cin >> t;
    solve();
    while (t --) {
        init();
        print();
    }
    return 0;
}