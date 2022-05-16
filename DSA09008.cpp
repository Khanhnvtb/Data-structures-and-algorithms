//
// Created by KhanhNVTB on 12/05/2021.
//
#include<bits/stdc++.h>
using namespace std;
int a[1005][1005], lt[1005], v, e, k,cnt;
void DFS(int u) {
    cnt++;
    lt[u] = 1;
    if (cnt == v) {
        return;
    }
    for (int i = 1 ; i <= v ; i++) {
        if (lt[i] == 0 && a[u][i] == 1) {
            lt[i] = k;
            DFS (i);
        }
    }
}
int TPLT_DFS() {
    memset (lt, 0, sizeof (lt));
    cnt = 0;
    for (int i = 1 ; i <= v ; i++) {
        if (lt[i] == 0) {
            k++;
            DFS (i);
        }
    }
    return k;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        k = 0;
        memset (a, 0, sizeof (a));
        while (e--) {
            int i, j;
            cin >> i >> j;
            a[i][j] = 1;
            a[j][i] = 1;
        }
        cout << TPLT_DFS () << endl;
    }
    return 0;
}
