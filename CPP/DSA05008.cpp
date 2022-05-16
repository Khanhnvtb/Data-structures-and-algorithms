//
// Created by khanh on 5/20/2021.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t --) {
        int n;
        long s;
        cin >> n >> s;
        int tmp, res[40005] = {0};
        for (int i = 1; i <= n; i ++) {
            cin >> tmp;
            res[tmp] = 1;
            for (long j = s; j > tmp; j --) {
                if (res[j - tmp] == 1) {
                    res[j] = 1;
                    if (j == s) {
                        break;
                    }
                }
            }
        }
        if (res[s]) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}