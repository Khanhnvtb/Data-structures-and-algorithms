//
// Created by khanh on 5/26/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, parent[1005];
vector <pair <int, int> > a;
void reset() {
    a.clear();
    memset(parent, - 1, sizeof(parent));
}
int find(int i) {
    if (parent[i] == - 1) {
        return i;
    }
    return find(parent[i]);
}
void Union(int x, int y) {
    parent[x] = y;
}
int isCycle() {
    for (int i = 0; i < e; i ++) {
        int x = find(a[i].first);
        int y = find(a[i].second);
        if (x == y) {
            return 1;
        }
        Union(x, y);
    }
    return 0;
}
void solve() {
    reset();
    cin >> v >> e;
    for (int i = 0; i < e; i ++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    if (isCycle()) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}