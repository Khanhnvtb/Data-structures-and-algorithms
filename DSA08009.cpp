//
// Created by khanh on 04/06/2021.
//

#include <bits/stdc++.h>
using namespace std;
int S, T;
void init() {
    cin >> S >> T;
}
int bfs() {
    set <int> s;
    queue <pair <int, int> > q;
    q.push({S, 0});
    while (! q.empty()) {
        int val = q.front().first;
        int cnt = q.front().second;
        if (val - 1 == T || val * 2 == T) return cnt + 1;
        if (s.find(val * 2) == s.end() && val < T) {
            q.push({val * 2, cnt + 1});
            s.insert(val * 2);
        }
        if (s.find(val - 1) == s.end() && val > 1) {
            q.push({val - 1, cnt + 1});
            s.insert(val - 1);
        }
        q.pop();
    }
}
void solve() {
    cout << bfs() << endl;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        init();
        solve();
    }
    return 0;
}