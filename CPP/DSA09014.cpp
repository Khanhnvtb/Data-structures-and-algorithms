//
// Created by khanh on 5/21/2021.
//
#include <bits/stdc++.h>
using namespace std;
int v, e, check, previous[1005], vs[1005];
vector <int> a[1005];
void bfs(int u) {
    queue <int> q;
    q.push(u);
    vs[u] = 1;
    while (! q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i ++) {
            int tmp = a[u][i];
            if (vs[tmp] == 0) {
                q.push(tmp);
                vs[tmp] = 1;
                previous[tmp] = u;
            } else if (vs[tmp] == 1 && tmp != previous[u]) {
                check = 1;
                return;
            }
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
        check = 0;
        memset(vs, 0, sizeof(vs));
        for (int i = 1; i <= v; i ++) {
            if (! vs[i]) {
                bfs(i);
            }
            if (check) {
                break;
            }
        }
        if (check) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
        for (int i = 1; i <= v; i ++) {
            a[i].clear();
        }
    }
    return 0;
}
