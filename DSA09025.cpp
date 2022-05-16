//
// Created by khanh on 5/15/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, first, last, vs[1005], previous[1005];
vector <int> a[1005];
vector <int> res;
void dfs(int u){
    if(vs[last]==1){
        return;
    }
    vs[u]=1;
    for(int i=0;i<a[u].size();i++){
        int tmp=a[u][i];
        if(!vs[tmp]){
            previous[tmp]=u;
            dfs(tmp);
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e >> first >> last;
        while (e--) {
            int x, y;
            cin >> x >> y;
            a[x].push_back (y);
        }
        memset (vs, 0, sizeof (vs));
        memset (previous, 0, sizeof (previous));
        dfs (first);
        if (vs[last] == 0) {
            cout << "-1";
        } else {
            res.clear ();
            while (last > 0) {
                res.push_back (last);
                last = previous[last];
            }
            for (int i = res.size () - 1 ; i >= 0 ; i--) {
                cout << res[i] << " ";
            }
        }
        cout << endl;
        for (int i = 1 ; i <= v ; i++) {
            a[i].clear ();
        }
    }
    return 0;
}