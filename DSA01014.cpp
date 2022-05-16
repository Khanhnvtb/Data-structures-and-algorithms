//
// Created by khanh on 5/17/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, k, s, cnt;
int a[25];
int main() {
    while (1) {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0) {
            break;
        }
        if (n < k) {
            cout << "0" << "\n";
        } else {
            cnt = 0;
            int sum = 0;
            for (int i = 1; i <= k; i ++) {
                a[i] = i;
                sum += i;
            }
            if (sum == s) {
                cnt ++;
            }
            while (1) {
                int i = k;
                sum = 0;
                while (i > 0 && a[i] == n - k + i) {
                    i --;
                }
                if (i > 0) {
                    a[i] ++;
                    for (int j = i + 1; j <= k; j ++) {
                        a[j] = a[i] + j - i;
                    }
                    for (int j = 1; j <= k; j ++) {
                        sum += a[j];
                    }
                    if (sum == s) {
                        cnt ++;
                    }
                } else {
                    break;
                }
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}
