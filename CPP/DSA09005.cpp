//
// Created by khanh on 5/18/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, vs[1005];
queue <int> q;
vector <int> a[1005];
void BFS(int u) {
    q.push(u);
    vs[u] = 1;
    while (! q.empty()) {
        u = q.front();
        cout << u << " ";
        q.pop();
        for (int i = 0; i < a[u].size(); i ++) {
            int tmp = a[u][i];
            if (vs[tmp] == 0) {
                q.push(tmp);
                vs[tmp] = 1;
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        int u;
        cin >> v >> e >> u;
        while (e --) {
            int i, j;
            cin >> i >> j;
            a[i].push_back(j);
            a[j].push_back(i);
        }
        memset(vs, 0, sizeof(vs));
        BFS(u);
        for (int i = 1; i <= v; i ++) {
            a[i].clear();
        }
        cout << endl;
    }
    return 0;
}