//
// Created by khanh on 5/20/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        int a[2 * n];
        for (int i = 0; i < 2 * n; i ++) {
            cin >> a[i];
        }
        for (int i = 0; i < 2 * n - 2; i += 2) {
            for (int j = i + 2; j < 2 * n; j += 2) {
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                    swap(a[i + 1], a[j + 1]);
                }
            }
        }
        int res[n];
        res[0] = 1;
        for (int i = 2; i < 2 * n; i += 2) {
            int tmp = i / 2;
            res[tmp] = 1;
            for (int j = 1; j < i; j += 2) {
                if (a[i] > a[j]) {
                    res[tmp] = max(res[tmp], res[(j - 1) / 2] + 1);
                }
            }
        }
        sort(res, res + n);
        cout << res[n - 1] << "\n";
    }
    return 0;
}