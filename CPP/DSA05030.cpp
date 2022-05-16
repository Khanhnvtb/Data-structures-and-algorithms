//
// Created by khanh on 5/29/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, m;
long res[30][30];
void init() {
    cin >> n >> m;
}
void solve() {
    for (int i = 0; i <= 25; i ++) {
        for (int j = 0; j <= 25; j ++) {
            if (i == 0 || j == 0) {
                res[i][j] = 1;
            } else {
                res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        }

    }
}
void print() {
    cout << res[n][m] << endl;
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