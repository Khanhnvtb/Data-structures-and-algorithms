//
// Created by khanh on 5/15/2021.
//

#include<bits/stdc++.h>
using namespace std;
int v, e, x, y;
vector <int> a[1005];
int vs[1005];
int previous[1005];
void dfs(int u) {
    vs[u] = 1;
    if (previous[y] != 0) {
        return;
    }
    for (int i = 0; i < a[u].size(); i++) {
        int t = a[u][i];
        if (vs[t] == 0) {
            previous[t] = u;
            dfs(t);
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        while (e--) {
            int i, j;
            cin >> i >> j;
            a[i].push_back(j);
            a[j].push_back(i);
        }
        int q;
        cin >> q;
        while (q--) {
            cin >> x >> y;
            for (int i = 1; i <= v; i++) {
                vs[i] = 0;
                previous[i] = 0;
            }
            dfs(x);
            if (previous[y] == 0) {
                cout << "NO" << "\n";
            } else {
                cout << "YES" << "\n";
            }
        }
        for (int i = 1; i <= v; i++) {
            a[i].clear();
        }
    }
    return 0;
}