//
// Created by khanh on 5/20/2021.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t --) {
        long n;
        cin >> n;
        long a[n];
        for (long i = 0; i < n; i ++) {
            cin >> a[i];
        }
        long long res[n];
        res[0] = a[0], res[1] = a[1], res[2] = a[0] + a[2];
        for (long i = 3; i < n; i ++) {
            res[i] = max(res[i - 2] + a[i], res[i - 3] + a[i]);
        }
        cout << max(res[n - 1], res[n - 2]) << "\n";
    }
    return 0;
}