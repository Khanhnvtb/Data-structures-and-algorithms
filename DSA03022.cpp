//
// Created by KhanhNVTB on 10/05/2021.
//
#include<bits/stdc++.h>
using namespace std;
main() {
    long n;
    cin >> n;
    long a[n];
    for (long i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    sort (a, a + n);
    long long res;
    if (a[n - 1] <= 0) {
        res = a[0] * a[1];
    } else if (a[n - 3] > 0) {
        if (a[0] * a[1] < a[n - 3] * a[n - 2]) {
            res = a[n - 1] * a[n - 2] * a[n - 3];
        } else {
            res = a[0] * a[1] * a[n - 1];
        }
    } else if (a[n - 2] <= 0 && a[n - 1] > 0) {
        res = a[0] * a[1] * a[n - 1];
    } else if (a[n - 3] <= 0 && a[n - 2] > 0) {
        if (a[0] * a[1] > a[n - 2]) {
            res = a[0] * a[1] * a[n - 1];
        } else {
            res = a[n - 2] * a[n - 1];
        }
    }
    cout << res << "\n";
    return 0;
}

