//
// Created by khanh on 5/19/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, a[1000], res;
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        res = 0;
        int check, pos;
        for (int i = 0; i < n - 1; i ++) {
            check = 0;
            pos = i;
            for (int j = i + 1; j < n; j ++) {
                if (a[j] < a[pos]) {
                    pos = j;
                    check = 1;
                }
            }
            if (check) {
                res ++;
                swap(a[i], a[pos]);
            }
        }
        cout << res << "\n";
    }
    return 0;
}