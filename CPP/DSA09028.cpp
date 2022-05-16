//
// Created by khanhnvtb on 11/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;
int v, e, m, color[105];
vector <int> edge[15];
void init() {
    cin >> v >> e >> m;
    int i, j;
    while (e--) {
        cin >> i >> j;
        edge[i].push_back (j);
        edge[j].push_back (i);
    }
}
int coloring(int u, int cl) {
    for (int i = 0; i < edge[u].size (); i++) {
        if (color[edge[u][i]] == cl) return 0;
    }
    return 1;
}
int Try(int i) {
    if (i == v + 1) return 1;
    for (int j = 1; j <= m; j++) {
        if (coloring (i, j)) {
            color[i] = j;
            if (Try (i + 1)) return 1;
            color[i] = 0;
        }
    }
    return 0;
}
void solve() {
    memset (color, 0, sizeof (color));
    if (Try (1)) cout << "YES";
    else cout << "NO";
    cout << endl;
    for (int i = 1; i <= v; i++) edge[i].clear ();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        init();
        solve();
    }
    return 0;
}