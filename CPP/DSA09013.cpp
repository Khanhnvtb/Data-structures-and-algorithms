//
// Created by khanh on 5/25/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, lt[1005];
vector <int> a[1005];
void reset() {
    for (int i = 1; i <= v; i ++) {
        lt[i] = 0;
    }
}
int bfs(int u) {
    lt[u] = 1;
    queue <int> q;
    q.push(u);
    int cnt=1;
    while (! q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i ++) {
            int tmp = a[u][i];
            if (! lt[tmp]) {
                lt[tmp] = 1;
                cnt++;
                q.push(tmp);
            }
        }
        return cnt;
    }
    int main() {
        int t;
        cin >> t;
        while (t --) {
            cin >> v >> e;
            reset();
            vector <pair <int, int> > edge;
            while (e --) {
                int x, y;
                cin >> x >> y;
                a[x].push_back(y);
                a[y].push_back(x);
                edge.push_back({x, y});
            }
            for (int i = 0; i < edge.size(); i ++) {
                int x = edge[i].first, y = edge[i].second;
                vector <int>::iterator i1, i2;
                i1 = find(a[x].begin(), a[x].end(), y);
                i2 = find(a[y].begin(), a[y].end(), x);
                a[x].erase(i1);
                a[y].erase(i2);
                reset();
                if (bfs(1) != v) {
                    cout << x << " " << y << " ";
                }
                a[x].insert(i1, y);
                a[y].insert(i2, x);
            }
            for (int i = 1; i <= v; i ++) {
                a[i].clear();
            }
            cout << endl;
        }
        return 0;
    }