//
// Created by KhanhNVTB on 27/04/2021.
//
#include<bits/stdc++.h>
using namespace std;
main() {
    int t;
    cin >> t;
    while (t--) {
        int n, v;
        cin >> n >> v;
        int a[n + 1], c[n + 1];
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
        }
        for (int i = 1 ; i <= n ; i++) {
            cin >> c[i];
        }
        int res[n + 1][v + 1];
        for (int i = 0 ; i <= n ; i++) {
            for (int j = 0 ; j <= v ; j++) {
                res[i][j] = 0;
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= v ; j++) {
                if (j >= a[i]) {
                    res[i][j] = max (res[i - 1][j], c[i] + res[i - 1][j - a[i]]);
                } else {
                    res[i][j] = res[i - 1][j];
                }
            }
        }
        cout << res[n][v];
        cout << endl;
    }
    return 0;
}
