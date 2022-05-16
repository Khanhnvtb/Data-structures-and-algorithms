//
// Created by khanh on 02/06/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, check, vs[1005];
vector <int> edge[1005];
void init() {
    cin >> v >> e;
    while (e --) {
        int i, j;
        cin >> i >> j;
        edge[i].push_back(j);
        edge[j].push_back(i);
    }
}
void bfs(int u) {
    vs[u] = 1;
    queue <int> q;
    q.push(u);
    while (! q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < edge[u].size(); i ++) {
            int tmp = edge[u][i];
            if (! vs[tmp]) {
                if (vs[u] == 1) {
                    vs[tmp] = 2;
                } else {
                    vs[tmp] = 1;
                }
                q.push(tmp);
            } else if (vs[tmp] == vs[u]) {
                check = 0;
                return;
            }
        }
    }
}
void solve() {
    for (int i = 1; i <= v; i ++) {
        vs[i] = 0;
    }
    check = 1;
    for (int i = 1; i <= v; i ++) {
        if (! vs[i]) {
            if (check) {
                bfs(i);
            } else {
                break;
            }
        }
    }
    for (int i = 1; i <= v; i ++) {
        edge[i].clear();
    }
}
void print() {
    if (check) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        init();
        solve();
        print();
    }
    return 0;
}