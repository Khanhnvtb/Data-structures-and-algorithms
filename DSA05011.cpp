//
// Created by khanh on 5/31/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n;
long res[105][50005], k, m=1e9+7;
void init() {
    cin >> n >> k;
}
long countRec(int i, long sum) {
    if (i == 0) {
        return sum == 0;
    }
    if (res[i][sum] != - 1) {
        return res[i][sum];
    }
    long ans = 0;
    for (int j = 0; j < 10; j ++) {
        if (sum - j >= 0) {
            ans = (ans % m + countRec(i - 1, sum - j) % m) % m;
        }
    }
    return res[i][sum] = ans;
}
long finalCount(int i, long sum) {
    long ans = 0;
    for (int j = 1; j < 10; j ++) {
        if (sum - j >= 0) {
            ans = (ans % m + countRec(i - 1, sum - j) % m) % m;
        }
    }
    return ans;
}
void solve() {
    cout << finalCount(n, k) << endl;
}
int main() {
    int t;
    cin >> t;
    memset(res, - 1, sizeof(res));
    while (t --) {
        init();
        solve();
    }
    return 0;
}