//
// Created by khanh on 5/19/2021.
//

#include <bits/stdc++.h>
using namespace std;

int t, n, a[1005], tmp[1005];
int main() {
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        tmp[0] = 1;
        int tmp_max;
        for (int i = 1; i < n; i ++) {
            tmp_max = 0;
            for (int j = 0; j < i; j ++) {
                if (a[i] >= a[j]) {
                    tmp_max = max(tmp_max, tmp[j]);
                }
            }
            tmp[i] = tmp_max + 1;
        }
        sort(tmp, tmp + n);
        cout << n - tmp[n - 1] << endl;
    }
    return 0;
}