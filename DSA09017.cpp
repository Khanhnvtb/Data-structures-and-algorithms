//
// Created by khanh on 5/23/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, vs[1005];
vector <int> a[1005];
void bfs(int u) {
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
                q.push(tmp);
            }
        }
    }
}
bool isTree() {
    bfs(1);
    for (int i = 1; i <= v; i ++) {
        if (vs[i] == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> v;
        for (int i = 0; i < v - 1; i ++) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        memset(vs, 0, sizeof(vs));
        if (isTree()) {
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