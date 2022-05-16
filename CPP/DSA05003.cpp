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
        int x, y, z;
        cin >> x >> y >> z;
        string str1, str2, str3;
        cin >> str1 >> str2 >> str3;
        int res[x + 1][y + 1][z + 1];
        for (int i = 0; i <= x; i ++) {
            for (int j = 0; j <= y; j ++) {
                for (int k = 0; k <= z; k ++) {
                    if (i == 0 || j == 0 || k == 0) {
                        res[i][j][k] = 0;
                    } else if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1]) {
                        res[i][j][k] = res[i - 1][j - 1][k - 1] + 1;
                    } else {
                        res[i][j][k] = max(res[i - 1][j][k], max(res[i][j - 1][k], res[i][j][k - 1]));
                    }
                }
            }
        }
        cout << res[x][y][z] << "\n";
    }
    return 0;
}