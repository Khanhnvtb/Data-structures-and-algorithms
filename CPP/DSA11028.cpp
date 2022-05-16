#include <bits/stdc++.h>
using namespace std;
int v;
vector <int> a[100005];
void init() {
    cin >> v;
    int x, y;
    for (int i = 1; i < v; i++) {
        cin >> x >> y;
        a[x].push_back (y);
    }
}
int maxHigh() {
    queue <pair <int, int> > q;
    q.push ({1, 0});
    int res = 0;
    while (!q.empty ()) {
        int tmp = q.front ().first;
        int cnt = q.front ().second;
        q.pop ();
        res = max (res, cnt);
        for (int i = 0; i < a[tmp].size (); i++) {
            q.push ({a[tmp][i], cnt + 1});
        }
    }
    return res;
}
void solve() {
    cout << maxHigh () << endl;
    for(int i=1;i<=v;i++){
        a[i].clear();
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}