//
// Created by KhanhNVTB on 05/05/2021.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int a[n + 1][m + 1];
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                cin >> a[i][j];
            }
        }
        long d[n + 1][m + 1];
        for (int i = 0 ; i <= n ; i++) {
            for (int j = 0 ; j <= m ; j++) {
                if (i == 0 || j == 0) {
                    d[i][j] = LONG_MAX;
                } else {
                    if (i == 1 && j == 1) {
                        d[i][j] = a[i][j];
                    } else {
                        d[i][j] = min (d[i - 1][j], d[i][j - 1]);
                        d[i][j] = min (d[i][j], d[i - 1][j - 1]) + a[i][j];
                    }
                }
            }
        }
        cout << d[n][m] << "\n";
    }
    return 0;
}