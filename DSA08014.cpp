//
// Created by khanh on 5/28/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, res, a[505][505];
queue <pair <int, int> > q;
void init() {
    while (! q.empty()) {
        q.pop();
    }
    cin >> n >> m;
    cnt = 0, res = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                cnt ++;
            } else if (a[i][j] == 2) {
                q.push({i, j});
            }
        }
    }
}
int bfs() {
    int tmp = q.size();
    while (! q.empty()) {
        tmp --;
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i > 0 && a[i - 1][j] == 1) {
            a[i - 1][j] = 2;
            cnt --;
            q.push({i - 1, j});
        }
        if (j > 0 && a[i][j - 1] == 1) {
            a[i][j - 1] = 2;
            cnt --;
            q.push({i, j - 1});
        }
        if (i < n - 1 && a[i + 1][j] == 1) {
            a[i + 1][j] = 2;
            cnt --;
            q.push({i + 1, j});
        }
        if (j < m - 1 && a[i][j + 1] == 1) {
            a[i][j + 1] = 2;
            cnt --;
            q.push({i, j + 1});
        }
        if (cnt == 0) {
            return res;
        }
        if (tmp == 0) {
            tmp = q.size();
            res ++;
        }
    }
    return - 1;
}
void solve() {
    cout << bfs() << "\n";
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        init();
        solve();
    }
    return 0;
}