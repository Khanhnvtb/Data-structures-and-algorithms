//
// Created by khanh on 5/21/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, cnt, res, vs[100005];
vector <int> a[100005];
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
        while (e --) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        res = 0;
        memset(vs, 0, sizeof(vs));
        for (int i = 1; i <= v; i ++) {
            if (vs[i] == 0) {
                cnt = 1;
                dfs(i);
                res = max(cnt, res);
            }
        }
        cout << res << "\n";
        for (int i = 1; i <= v; i ++) {
            a[i].clear();
        }
    }
    return 0;
}

