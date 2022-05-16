//
// Created by khanh on 5/15/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, x, y, vs[1005], cnt;
vector <int> a[1005];
void bfs(int u) {
    if (cnt == v) {
        return;
    }
    cout << u << " ";
    vs[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int tmp = a[u][i];
        if (!vs[tmp]) {
            cnt++;
            bfs(tmp);
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int u;
        cin >> v >> e >> u;
        for (int i = 1; i <= v; i++) {
            a[i].clear();
            vs[i] = 0;
        }
        cnt = 0;
        while (e--) {
            cin >> x >> y;
            a[x].push_back(y);
        }
        bfs(u);
        cout << endl;
    }
    return 0;
}