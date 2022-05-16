//
// Created by khanh on 5/26/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, res, vs[105][105];
char a[105][105];
void dfs(int i, int j) {
    vs[i][j] = 1;
    if (a[i - 1][j] == 'W' && vs[i - 1][j] == 0) {
        dfs(i - 1, j);
    }
    if (a[i - 1][j - 1] == 'W' && vs[i - 1][j - 1] == 0) {
        dfs(i - 1, j - 1);
    }
    if (a[i - 1][j + 1] == 'W' && vs[i - 1][j + 1] == 0) {
        dfs(i - 1, j + 1);
    }
    if (a[i][j - 1] == 'W' && vs[i][j - 1] == 0) {
        dfs(i, j - 1);
    }
    if (a[i][j + 1] == 'W' && vs[i][j + 1] == 0) {
        dfs(i, j + 1);
    }
    if (a[i + 1][j - 1] == 'W' && vs[i + 1][j - 1] == 0) {
        dfs(i + 1, j - 1);
    }
    if (a[i + 1][j] == 'W' && vs[i + 1][j] == 0) {
        dfs(i + 1, j);
    }
    if (a[i + 1][j + 1] == 'W' && vs[i + 1][j + 1] == 0) {
        dfs(i + 1, j + 1);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    memset(vs, 0, sizeof(vs));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (a[i][j] == 'W' && vs[i][j] == 0) {
                res ++;
                dfs(i, j);
            }
        }
    }
    cout << res << "\n";
    return 0;
}