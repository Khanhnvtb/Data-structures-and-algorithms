//
// Created by khanh on 5/24/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, s, d[1005];
vector <pair <int, int> > a[1005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > b;
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> v >> e >> s;
        while (e --) {
            int x, y, z;
            cin >> x >> y >> z;
            a[x].push_back({z, y});
            a[y].push_back({z, x});
        }
        for (int i = 1; i <= v; i ++) {
            d[i] = INT_MAX;
        }
        while (! b.empty()) {
            b.pop();
        }
        d[s] = 0;
        b.push({0, s});
        while (! b.empty()) {
            s = b.top().second;
            b.pop();
            for (int i = 0; i < a[s].size(); i ++) {
                int x = a[s][i].second;
                int y = a[s][i].first;
                if (d[x] > d[s] + y) {
                    d[x] = d[s] + y;
                    b.push({d[x], x});
                }
            }
        }
        for (int i = 1; i <= v; i ++) {
            cout << d[i] << " ";
        }
        cout << endl;
        for (int i = 1; i <= v; i ++) {
            a[i].clear();
        }
    }
    return 0;
}