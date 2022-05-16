//
// Created by khanhnvtb on 15/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int dp[n + 1][k];
    dp[0][0] = 0;
    for (int i = 1; i < k; i++) {
        dp[0][i] = INT_MIN;
    }
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        a %= k;
        for (int j = 0; j < k; j++) {
            dp[i][j] = max (dp[i - 1][j], dp[i - 1][(j + k - a) % k] + 1);
        }
    }
    cout << dp[n][0] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve ();
    }
    return 0;
}