//
// Created by KhanhNVTB on 05/05/2021.
//

#include <bits/stdc++.h>
using namespace std;
long m=1e9+7;
long n,k;
long a[1005];
main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a[0] = 1, a[1] = 1;
        for (int i = 2 ; i <= k ; i++) {
            a[i] = 0;
            for (int j = 1 ; j <= i ; j++) {
                a[i] += a[i - j];
                a[i] %= m;
            }
        }
        for (int i = k + 1 ; i <= n ; i++) {
            a[i] = 0;
            for (int j = 1 ; j <= k ; j++) {
                a[i] += a[i - j];
                a[i] %= m;
            }
        }
        cout << a[n];
        cout << endl;
    }
    return 0;
}