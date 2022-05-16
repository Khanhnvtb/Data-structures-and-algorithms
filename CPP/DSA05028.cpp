//
// Created by khanh on 5/20/2021.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t --) {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.length(), m = s2.length();
        int res[n + 1][m + 1];
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0 || j == 0) {
                    res[i][j] = i + j;
                } else if (s1[i - 1] == s2[j - 1]) {
                    res[i][j] = res[i - 1][j - 1];
                } else {
                    res[i][j] = min(res[i - 1][j - 1], min(res[i - 1][j], res[i][j - 1])) + 1;
                }
            }
        }
        cout << res[n][m] << "\n";
    }
    return 0;
}