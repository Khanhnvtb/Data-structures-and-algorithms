//
// Created by khanh on 5/20/2021.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t --) {
        string str;
        cin >> str;
        int n = str.length(), res[n + 1];
        if (str[0] == '0') {
            cout << "0" << "\n";
        } else {
            res[0] = 1, res[1] = 1;
            for (int i = 2; i <= n; i ++) {
                res[i] = 0;
                if (str[i - 1] > '0') {
                    res[i] = res[i - 1];
                }
                if (str[i - 2] == '1' || str[i - 2] == '2' && str[i - 1] < '7') {
                    res[i] += res[i - 2];
                }
            }
            cout << res[n] << "\n";
        }
    }
    return 0;
}