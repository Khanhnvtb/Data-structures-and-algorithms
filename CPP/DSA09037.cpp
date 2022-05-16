//
// Created by khanhnvtb on 14/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int k, n, m, vs[1005];
vector <int> edge[1005];
vector <int> a;
set <int> res;
set <int>::iterator it;

void init() {
    cin >> k >> n >> m;
    while (k--) {
        int x;
        cin >> x;
        a.push_back (x);
    }
    int i, j;
    while (m--) {
        cin >> i >> j;
        edge[i].push_back (j);
    }
}

void reset() {
    for (int i = 1; i <= n; i++) {
        vs[i] = 0;
    }
}

void bfs(int u) {
    set <int> s;
    for (it = res.begin (); it != res.end (); it++) {
        s.insert (*it);
    }
    res.clear ();
    res.insert (u);
    queue <int> q;
    q.push (u);
    while (!q.empty ()) {
        u = q.front ();
        q.pop ();
        for (int i = 0; i < edge[u].size (); i++) {
            int tmp = edge[u][i];
            if (!vs[tmp] && s.find (tmp) != s.end ()) {
                res.insert (tmp);
                q.push (tmp);
                vs[tmp] = 1;
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        res.insert (i);
    }
    for (int i = 0; i < a.size (); i++) {
        reset ();
        bfs (a[i]);
    }
    cout << res.size () << endl;
    res.clear ();
}

int main() {
    init ();
    solve ();
    return 0;
}
