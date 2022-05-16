//
// Created by khanh on 5/19/2021.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        int sum_first[n], sum_last[n];
        sum_first[0] = a[0], sum_last[n - 1] = a[n - 1];
        for (int i = 1; i < n; i ++) {
            sum_first[i] = a[i];
            for (int j = 0; j < i; j ++) {
                if (a[i] > a[j]) {
                    sum_first[i] = max(sum_first[i], sum_first[j] + a[i]);
                }
            }
        }
        for (int i = n - 2; i >= 0; i --) {
            sum_last[i] = a[i];
            for (int j = n - 1; j > i; j --) {
                if (a[i] > a[j]) {
                    sum_last[i] = max(sum_last[i], sum_last[j] + a[i]);
                }
            }
        }
        int res=0;
        for (int i = 0; i < n; i ++) {
            res = max(sum_first[i] + sum_last[i] - a[i], res);
        }
        cout << res << "\n";
    }
    return 0;
}