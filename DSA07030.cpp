//
// Created by khanhnvtb on 16/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int     n , m , a[505][505];
int     h[505] , l[505] , r[505] , res;

void init() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
}

void solve() {
    res=0;
    h[0] = -1;
    h[n + 1] = -1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            h[j] = a[i][j] * (h[j] + 1);
        for (int j = 1; j <= n; j++) {
            l[j] = j;
            while (h[l[j] - 1] >= h[j]) l[j] = l[l[j] - 1];
        }
        for (int j = n; j > 0; j--) {
            r[j] = j;
            while (h[r[j] + 1] >= h[j]) r[j] = r[r[j] + 1];
        }
        for (int j = 1; j <= n; j++)
            res = max (res, h[j] * (r[j] - l[j] + 1));
    }
    cout << res << endl;
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