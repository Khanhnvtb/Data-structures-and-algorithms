//
// Created by khanh on 5/23/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, vs[1005], degin[1005], degout[1005];
vector <int> a[1005];
int bfs(int u) {
    vs[u] = 1;
    queue <int> q;
    q.push (u);
    int cnt = 1;
    while (!q.empty ()) {
        u = q.front ();
        q.pop ();
        for (int i = 0; i < a[u].size (); i++) {
            int tmp = a[u][i];
            if (!vs[tmp]) {
                cnt++;
                vs[tmp] = 1;
                q.push (tmp);
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
        memset(vs, 0, sizeof(vs));
        memset(degin, 0, sizeof(degin));
        memset(degout, 0, sizeof(degout));
        while (e --) {
            int x, y;
            cin >> x >> y;
            degout[x] ++;
            degin[y] ++;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        int check = 1;
        for (int i = 1; i <= v; i ++) {
            if (degin[i] != degout[i]) {
                check = 0;
                break;
            }
        }
        if (check && bfs(1) != v) {
            check = 0;
        }
        cout << check << "\n";
    }
    return 0;
}