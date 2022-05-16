//
// Created by khanhnvtb on 18/06/2021.
//
/* Ý tưởng: 
*/
//khuyến khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int n, a[1005];

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void solve() {
    sort (a, a + n);
    if (n % 2 == 0) cout << a[n / 2 - 1] << endl;
    else cout << a[n / 2] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}