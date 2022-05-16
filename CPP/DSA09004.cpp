//
// Created by KhanhNVTB on 10/05/2021.
//
#include <bits/stdc++.h>
using namespace std;
int v,e;
int vs[1005];
int a[1005][1005];
void dfs(int u) {
    cout << u << " ";
    vs[u] = 1;
    for (int i = 1 ; i <= v ; i++) {
        if (vs[i] == 0 && a[u][i] == 1) {
            dfs (i);
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int u;
        cin >> v >> e >> u;
        memset (a, 0, sizeof (a));
        memset (vs, 0, sizeof (vs));
        for(int i=0;i<e;i++){
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
            a[y][x] = 1;
        }
        dfs (u);
        cout << endl;
    }
    return 0;
}
