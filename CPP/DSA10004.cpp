//
// Created by khanh on 5/21/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, res, cnt, vs[1005], deg[1005];
vector <int> a[1005];
void dfs(int u) {
    vs[u] = 1;
    for (int i = 0; i < a[u].size(); i ++) {
        int tmp = a[u][i];
        if (vs[tmp] == 0) {
            cnt ++;
            dfs(tmp);
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> v >> e;
        memset(deg, 0, sizeof(deg));
        while (e --) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
            deg[x] ++;
            deg[y] ++;
        }
        cnt = 0;
        for (int i = 1; i <= v; i ++) {
            if (deg[i] % 2 == 1) {
                cnt ++;
            }
        }
        if (cnt > 2) {
            res = 0;
        } else if (cnt == 0) {
            res = 2;
            cnt = 1;
            memset(vs, 0, sizeof(vs));
            dfs(1);
            if (cnt != v) {
                res = 0;
            }
        } else {
            res = 1;
            cnt = 1;
            memset(vs, 0, sizeof(vs));
            dfs(1);
            if (cnt != v) {
                res = 0;
            }
        }
        for (int i = 1; i <= v; i ++) {
            a[i].clear();
        }
        cout << res << "\n";
    }
    return 0;
}