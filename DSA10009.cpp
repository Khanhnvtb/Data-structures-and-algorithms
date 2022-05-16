//
// Created by khanh on 5/24/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, e, d[105][105];
int main() {
    cin >> n >> e;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = INT_MAX;
            }
        }
    }
    while (e --) {
        int i, j, k;
        cin >> i >> j >> k;
        d[i][j] = k;
        d[j][i]=k;
    }
    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (d[i][k] != INT_MAX && d[k][j]!= INT_MAX && d[i][j]>d[i][k]+d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q --) {
        int u, v;
        cin >> u >> v;
        cout << d[u][v] << "\n";
    }
    return 0;
}