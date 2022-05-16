//
// Created by khanh on 5/22/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, vs[1005];
vector <int> a[1005];
int bfs(int u,int cnt) {
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
            }
        }
    }
    return cnt;
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
        }
        int check = 1;
        for (int i = 1; i <= v; i ++) {
            memset(vs, 0, sizeof(vs));
            if (bfs(i, 1) != v) {
                check = 0;
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