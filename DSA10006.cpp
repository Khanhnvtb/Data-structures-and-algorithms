//
// Created by khanh on 5/23/2021.
//
#include <bits/stdc++.h>
using namespace std;
int v, e, cnt, vs[1005];
vector <int> a[1005];
vector <int> res;
void dfs(int u) {
    vs[u] = 1;
    queue <int> q;
    q.push(u);
    while (! q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i ++) {
            int tmp = a[u][i];
            if (! vs[tmp]) {
                vs[tmp] = 1;
                cnt ++;
                q.push(tmp);
                res.push_back(u);
                res.push_back(tmp);
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        int u;
        res.clear();
        cin >> v >> e >> u;
        while (e --) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        cnt = 0;
        memset(vs, 0, sizeof(vs));
        bfs(u);
        if (cnt == v) {
            for (int i = 0; i < res.size(); i += 2) {
                cout << res[i] << " " << res[i + 1] << "\n";
            }
        } else {
            cout << "-1" << "\n";
        }
        for (int i = 1; i <= v; i ++) {
            a[i].clear();
        }
    }
    return 0;
}
