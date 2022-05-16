//
// Created by khanhnvtb on 12/06/2021.
//
/* Ý tưởng: để là mạng xã hội hoàn hoả thì với mỗi thành phần liên thông gồm n đỉnh thì sẽ cần có n * (n - 1) / 2 cạnh.
Thực hiện đếm số cạnh của mạng xã hội hoàn hảo nếu bằng với số cạnh ch trước thì trả về kết quả đúng.
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int v, e, cntEdge, vs[100005];
vector <int> edge[100005];

void init() {
    cin >> v >> e;
    int x, y;
    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        edge[x].push_back (y);
        edge[y].push_back (x);
    }
}

void bfs(int u) {
    vs[u] = 1;
    queue <int> q;
    q.push (u);
    int cnt = 1;
    while (!q.empty ()) {
        u = q.front ();
        q.pop ();
        for (int i = 0; i < edge[u].size (); i++) {
            int tmp = edge[u][i];
            if (!vs[tmp]) {
                cnt++;
                vs[tmp] = 1;
                q.push (tmp);
            }
        }
    }
    cntEdge += cnt * (cnt - 1) / 2;
}

void solve() {
    cntEdge = 0;
    for (int i = 1; i <= v; i++) vs[i] = 0;
    for (int i = 1; i <= v; i++) {
        if (!vs[i]) bfs (i);
    }
    if (cntEdge != e) cout << "NO";
    else cout << "YES";
    cout << endl;
    for (int i = 1; i <= v; i++) {
        edge[i].clear ();
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