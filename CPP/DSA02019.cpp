#include <bits/stdc++.h>
using namespace std;
int v, e, res, vs[20][20];
vector<int>a[20];
void Try(int i, int cnt) {
    res = max(res, cnt);
    for (int j = 0; j < a[i].size(); j ++) {
        int t = a[i][j];
        if (vs[i][t] == 0) {
            vs[i][t] = 1;
            vs[t][i] = 1;
            cnt ++;
            Try(t, cnt);
            vs[i][t] = 0;
            vs[t][i] = 0;
            cnt --;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> v >> e;
        res = INT_MIN;
        while (e --) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 0; i < v; i ++) {
            memset(vs, 0, sizeof(vs));
            Try(i, 0);
        }
        for (int i = 0; i < v; i ++) {
            a[i].clear();
        }
        cout << res << "\n";
    }
    return 0;
}