//
// Created by khanh on 5/31/2021.
//

#include <bits/stdc++.h>
using namespace std;
string str;
int res[50][50];
void init() {
    cin >> str;
}
void solve() {
    memset(res, 0, sizeof(res));
    for (int i = 1; i < str.length(); i ++) {
        for (int j = 0, k = i; k < str.length(); j ++, k ++) {
            if (str[j] == str[k]) {
                res[j][k] = res[j + 1][k - 1];
            } else {
                res[j][k] = min(res[j + 1][k], res[j][k - 1]) + 1;
            }
        }
    }
}
void print() {
    cout << res[0][str.length() - 1] << endl;
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