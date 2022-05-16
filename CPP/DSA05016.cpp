//
// Created by khanh on 5/26/2021.
//

#include <bits/stdc++.h>
using namespace std;
unsigned long long a[10005], x1 = 1, x2 = 1, x3 = 1;
long n;
int main() {
    int t;
    cin >> t;
    a[1] = 1;
    for (long i = 2; i <= 10005; i ++) {
        a[i] = min(a[x1] * 2, min(a[x2] * 3, a[x3] * 5));
        if (a[i] == a[x1] * 2) {
            x1 ++;
        }
        if (a[i] == a[x2] * 3) {
            x2 ++;
        }
        if (a[i] == a[x3] * 5) {
            x3 ++;
        }
    }
    while (t --) {
        cin >> n;
        cout << a[n] << "\n";
    }
    return 0;
}