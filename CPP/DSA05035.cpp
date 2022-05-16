//
// Created by khanhnvtb on 16/06/2021.
//
/* Ý tưởng: số các số có i chữ số không giảm bắt đầu từ chữ số j bằng tổng của số các số có i-1 chữ số không giảm bắt
đầu từ chữ số j với số các số có i chữ số không giảm bắt đầu từ j+1.
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int n, previous;
long m=1e9+7, dp[105][10];

void init() {
    previous = 1;
    for (int i = 0; i < 10; i++) dp[0][i] = 1;
    for (int i = 0; i <= 100; i++) dp[i][9] = 1;
}

void solve() {
    for (int i = previous; i <= n; i++) {
        for (int j = 8; j >= 0; j--) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j + 1]) % m;
        }
    }
    previous = n + 1;
    cout << dp[n][0] << endl;
}

int main() {
    int t;
    cin >> t;
    init ();
    while (t--) {
        cin >> n;
        solve ();
    }
    return 0;
}