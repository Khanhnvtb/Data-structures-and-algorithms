//
// Created by khanh on 5/21/2021.
//
#include <bits/stdc++.h>
using namespace std;
int v, e, check;
vector <int> a[1005];
int vs[1005];
void bfs(int u) {
    if (check) {
        return;
    }
    for (int i = 0; i < a[u].size(); i ++) {
        int tmp = a[u][i];
        if (vs[tmp] == 0) {
            vs[tmp] = 1;
            bfs(tmp);
            vs[tmp] = 2;
        } else if (vs[tmp] == 1) {
            check = 1;
            return;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        check = 0;
        cin >> v >> e;
        while (e --) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
        }
        memset(vs, 0, sizeof(vs));
        for (int i = 1; i <= v; i ++) {
            if (vs[i] == 0) {
                vs[i] = 1;
                bfs(i);
                vs[i] = 2;
                if (check == 1) {
                    cout << "YES" << "\n";
                    break;
                }
            }
        }
        if (check == 0) {
            cout << "NO" << "\n";
        }
        for (int i = 1; i <= v; i ++) {
            a[i].clear();
        }
    }
    return 0;
}
