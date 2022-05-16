//
// Created by khanh on 5/18/2021.
//
#include <bits/stdc++.h>
using namespace std;
int v, e, first, last, vs[1005], previos[1005];
queue <int> q;
vector <int> a[1005];
void BFS(int u) {
    q.push(u);
    vs[u] = 1;
    while (! q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i ++) {
            int tmp = a[u][i];
            if (vs[tmp] == 0) {
                q.push(tmp);
                vs[tmp] = 1;
                previos[tmp] = u;
                if (tmp == last) {
                    return;
                }
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> v >> e >> first >> last;
        while (e --) {
            int i, j;
            cin >> i >> j;
            a[i].push_back(j);
        }
        memset(vs, 0, sizeof(vs));
        memset(previos, 0, sizeof(previos));
        BFS(first);
        for (int i = 1; i <= v; i ++) {
            a[i].clear();
        }
        if (previos[last] == 0) {
            cout << "-1";
        } else {
            vector <int> res;
            while (last > 0) {
                res.push_back(last);
                last = previos[last];
            }
            for (int i = res.size() - 1; i >= 0; i --) {
                cout << res[i] << " ";
            }
        }
        while (! q.empty()) {
            q.pop();
        }
        cout << endl;
    }
    return 0;
}
