//
// Created by khanh on 5/18/2021.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int check;
    long long res = 0;
    for (int i = 1; i <= a[n - 1] / 2 + 1; i ++) {
        check = 1;
        int x = a[n - 1] / i;
        b[n - 1] = i;
        for (int j = n - 2; j >= 0; j --) {
            int tmp = a[j] / x;
            if (tmp == 0 || a[j] / tmp > x) {
                check = 0;
                break;
            } else {
                while (tmp > 1 && a[j] / (tmp - 1) == x) {
                    tmp --;
                }
                b[j] = tmp;
            }
        }
        if (check == 1) {
            break;
        }
    }
    for (int i = 0; i < n; i ++) {
        res += b[i];
    }
    cout << res;
    return 0;
}