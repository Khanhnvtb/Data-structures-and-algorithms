//
// Created by khanh on 02/06/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, check, vs[20];
vector <int> a[20];
void init() {
    cin >> v >> e;
    while (e --) {
        int i, j;
        cin >> i >> j;
        a[i].push_back(j);
        a[j].push_back(i);
    }
}
void dfs(int u, int cnt) {
    if (check) {
        return;
    }
    for (int i = 0; i < a[u].size(); i ++) {
        int tmp = a[u][i];
        if (! vs[tmp]) {
            vs[tmp] = 1;
            cnt ++;
            if (cnt == v) {
                check = 1;
                return;
            }
            dfs(tmp, cnt );
            vs[tmp] = 0;
            cnt --;
        }
    }
}
void solve() {
    check = 0;
    for (int i = 1; i <= v; i ++) {
        memset(vs, 0, sizeof(vs));
        vs[i] = 1;
        dfs(i, 1);
        if (check) {
            break;
        }
    }
    for (int i = 1; i <= v; i ++) {
        a[i].clear();
    }
}
void print() {
    if (check) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        init();
        solve();
        print();
    }
    return 0;
}