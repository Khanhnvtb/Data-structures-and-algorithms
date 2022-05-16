//
// Created by khanhnvtb on 08/06/2021.
//
/* Ý tưởng:
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;
int n, Q, u, v, vs[1005];
vector <int> a[1005];
void init() {
    cin >> n;
    int x, y;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        a[x].push_back (y);
        a[y].push_back (x);
    }
    cin >> Q;
}
int bfs() {
    if (u == v) return 0;
    queue <pair <int, int> > q;
    q.push ({u, 0});
    vs[u] = 1;
    while (!q.empty ()) {
        u = q.front ().first;
        int cnt = q.front ().second + 1;
        q.pop ();
        for (int i = 0; i < a[u].size (); i++) {
            int tmp = a[u][i];
            if (!vs[tmp]) {
                if (tmp == v) return cnt;
                else {
                    vs[tmp] = 1;
                    q.push ({tmp, cnt});
                }
            }
        }
    }
}
void solve() {
    while (Q--) {
        cin >> u >> v;
        memset (vs, 0, sizeof (vs));
        cout << bfs () << endl;
    }
    for (int i = 1; i <= n; i++) {
        a[i].clear ();
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}