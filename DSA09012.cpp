//
// Created by khanh on 5/25/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, res, vs[1005];
vector <int> a[1005];
void reset() {
    for (int i = 1; i <= v; i ++) {
        vs[i] = 0;
    }
    vs[res] = 1;
}
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
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> v >> e;
        while (e --) {
            int i, j;
            cin >> i >> j;
            a[i].push_back(j);
            a[j].push_back(i);
        }
        for (res = 1; res <= v; res ++) {
            reset();
            if (res == 1) {
                bfs(2);
            } else {
                bfs(1);
            }
            for (int i = 1; i <= v; i ++) {
                if (! vs[i]) {
                    cout << res << " ";
                    break;
                }
            }
        }
        for (int i = 1; i <= v; i ++) {
            a[i].clear();
        }
        cout << endl;
    }
    return 0;
}