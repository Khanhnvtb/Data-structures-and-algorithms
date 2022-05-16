//
// Created by khanh on 5/19/2021.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int c, n;
    cin >> c >> n;
    int w[n + 1];
    for (int i = 1; i <= n; i ++) {
        cin>> w[i];
    }
    int res[n + 1][c + 1];
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= c; j ++) {
            if (w[i] <= j) {
                res[i][j] = max(w[i] + res[i - 1][j - w[i]], res[i - 1][j]);
            } else {
                res[i][j] = res[i - 1][j];
            }
        }
    }
    cout << res[n][c];
    return 0;
}
