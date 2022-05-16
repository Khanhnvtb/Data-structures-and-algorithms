//
// Created by KhanhNVTB on 13/05/2021.
//
#include <bits/stdc++.h>
using namespace std;
int v, e, vs[1005], check;
vector <int> a[1005];
void bfs(int u, int prev) {
    vs[u] = 1;
    for (int i = 0 ; i < a[u].size () ; i++) {
        int tmp = a[u][i];
        if (vs[tmp] == 0) {
            bfs (tmp, u);
        } else if (tmp != prev) {
            check = 1;
            break;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        check = 0;
        cin >> v >> e;
        while (e--) {
            int x, y;
            cin >> x >> y;
            a[x].push_back (y);
            a[y].push_back (x);
        }
        for (int i = 1 ; i <= v ; i++) {
            memset (vs, 0, sizeof (vs));
            bfs (i, 0);
            if (check == 1) {
                cout << "YES" << "\n";
                break;
            }
        }
        if (check == 0) {
            cout << "NO" << "\n";
        }
        for (int i = 1 ; i <= v ; i++) {
            a[i].clear ();
        }
    }
    return 0;
}
