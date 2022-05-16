//
// Created by khanh on 5/26/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, a[10], used[10];
void in() {
    for (int i = 1; i <= n; i ++) {
        cout << a[i];
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j ++) {
        if (used[j] == 0) {
            used[j] = 1;
            a[i] = j;
            int check = 1;
            if (i == n) {
                for (int k = 1; k < n; k ++) {
                    if (a[k] == a[k + 1] + 1 || a[k] == a[k + 1] - 1) {
                        check = 0;
                        break;
                    }
                }
                if (check) {
                    in();
                }
            } else {
                Try(i + 1);
            }
            used[j] = 0;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            used[i] = 0;
        }
        Try(1);
    }
    return 0;
}