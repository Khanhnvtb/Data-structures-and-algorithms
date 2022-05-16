#include <bits/stdc++.h>
using namespace std;
int N;
void init() {
    cin >> N;
}
int bfs() {
    if (N == 1) return 0;
    set <int> s;
    s.insert(N);
    queue <pair <int, int> > q;
    q.push({N, 0});
    while (! q.empty()) {
        int val = q.front().first;
        int cnt = q.front().second + 1;
        q.pop();
        for (int i = sqrt(val); i >= 2; i --) {
            if (val % i == 0 && s.find(val / i) == s.end()) {
                q.push({val / i, cnt});
                s.insert(val / i);
            }
        }
        if (val - 1 == 1) {
            return cnt;
        } else if (s.find(val - 1) == s.end()) {
            q.push({val - 1, cnt});
            s.insert(val - 1);
        }
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