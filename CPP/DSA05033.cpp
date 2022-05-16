//
// Created by khanh on 5/31/2021.
//
#include <bits/stdc++.h>
using namespace std;
string str;
int n, res[105][105];
void init() {
    cin.ignore();
    cin >> str;
    n = str.length();
}
void solve() {
    for (int i = 0; i < n - 1; i ++) {
        res[i][i] = 1;
    }
    for (int cl = 1; cl <= n; cl ++) {
        for (int i = 0; i < n - cl; i ++) {
            int j = i + cl;
            if (str[i] == str[j] && cl == 1) {
                res[i][j] = 2;
            } else if (str[i] == str[j]) {
                res[i][j] = res[i + 1][j - 1] + 2;
            } else {
                res[i][j] = max(res[i + 1][j], res[i][j - 1]);
            }
        }
    }
}
void print() {
    cout << n - res[0][n - 1] << endl;
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
