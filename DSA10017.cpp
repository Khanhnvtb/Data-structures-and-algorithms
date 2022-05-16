//
// Created by khanhnvtb on 14/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int v, e, negCycle, d[1005][1005];

void init() {
    cin >> v >> e;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INT_MAX;
        }
    }
    int i, j, k;
    while (e--) {
        cin >> i >> j >> k;
        d[i][j] = k;
    }
}

void solve() {
    negCycle = 0;
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (d[i][k] != INT_MAX && d[k][j] != INT_MAX && d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (d[i][i] < 0) {
            negCycle = 1;
            break;
        }
    }
    cout << negCycle << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}