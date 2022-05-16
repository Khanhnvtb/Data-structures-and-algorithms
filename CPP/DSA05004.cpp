//
// Created by KhanhNVTB on 05/05/2021.
//
#include<bits/stdc++.h>
using namespace std;
int n,res;
int a[1001];
main() {
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    int b[n + 1];
    res = 0;
    for (int i = 1 ; i <= n ; i++) {
        b[i] = 1;
        for (int j = 1 ; j < i ; j++) {
            if (a[i] > a[j]) {
                b[i] = max (b[i], b[j] + 1);
            }
        }
        res = max (res, b[i]);
    }
    cout << res << "\n";
    return 0;
}
