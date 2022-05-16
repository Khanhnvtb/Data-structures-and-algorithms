//
// Created by khanh on 5/22/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, res, lt[1005];
vector <int> a[1005];
void bfs(int u) {
    lt[u] = 1;
    queue <int> q;
    q.push(u);
    while (! q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i ++) {
            int tmp = a[u][i];
            if (! lt[tmp]) {
                lt[tmp] = res;
                q.push(tmp);
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> v >> e;
        while (e --) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        memset(lt, 0, sizeof(lt));
        res = 0;
        for (int i = 1; i <= v; i ++) {
            if (! lt[i]) {
                res ++;
                bfs(i);
            }
        }
        for (int i = 1; i <= v; i ++) {
            a[i].clear();
        }
        cout << res << "\n";
    }
    return 0;
}