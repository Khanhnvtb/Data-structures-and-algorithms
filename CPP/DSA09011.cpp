//
// Created by khanh on 5/26/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, res, vs[505][505], a[505][505];
void dfs(int i, int j) {
    vs[i][j] = 1;
    if (a[i - 1][j] == 1 && i > 1 && vs[i - 1][j] == 0) {
        dfs(i - 1, j);
    }
    if (a[i - 1][j - 1] == 1 && i > 1 && j > 1 && vs[i - 1][j - 1] == 0) {
        dfs(i - 1, j - 1);
    }
    if (a[i - 1][j + 1] == 1 && i > 1 && j < m && vs[i - 1][j + 1] == 0) {
        dfs(i - 1, j + 1);
    }
    if (a[i][j - 1] == 1 && j > 1 && vs[i][j - 1] == 0) {
        dfs(i, j - 1);
    }
    if (a[i][j + 1] == 1 && j < m && vs[i][j + 1] == 0) {
        dfs(i, j + 1);
    }
    if (a[i + 1][j - 1] == 1 && i < n && j > 1 && vs[i + 1][j - 1] == 0) {
        dfs(i + 1, j - 1);
    }
    if (a[i + 1][j] == 1 && i < n && vs[i + 1][j] == 0) {
        dfs(i + 1, j);
    }
    if (a[i + 1][j + 1] == 1 && i < n && j < m && vs[i + 1][j + 1] == 0) {
        dfs(i + 1, j + 1);
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                cin >> a[i][j];
            }
        }
        res = 0;
        memset(vs, 0, sizeof(vs));
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (a[i][j] == 1 && vs[i][j] == 0) {
                    res ++;
                    dfs(i, j);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}