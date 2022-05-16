//
// Created by khanhnvtb on 09/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int n, k, res;
long long a[15], sum;

void init() {
    cin >> n >> k;
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

void Try(int i, long long s, int cnt) {
    if (i < n - 1) {
        if (s + a[i] == sum * (cnt + 1)) {
            Try (i + 1, s + a[i], cnt + 1);
        }
        Try (i + 1, s + a[i], cnt);
    }
    if (i == n - 1) {
        if (cnt == k - 1) res++;
    }
}

void solve() {
    res = 0;
    if (sum % k == 0) {
        sum /= k;
        Try (0, 0, 0);
    }
    cout << res;
}

int main() {
    init ();
    solve ();
    return 0;
}