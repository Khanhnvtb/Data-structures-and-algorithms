//
// Created by khanh on 5/20/2021.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t --) {
        long n;
        cin >> n;
        long a[n];
        stack <long> s;
        for (long i = 0; i < n; i ++) {
            cin >> a[i];
        }
        long res[n];
        stack <long> cnt;
        res[0] = 1;
        for (long i = 1; i < n; i ++) {
            if (a[i] < a[i - 1]) {
                res[i] = 1;
                s.push(a[i - 1]);
                cnt.push(res[i - 1]);
            } else {
                res[i] = res[i - 1] + 1;
                while (! s.empty() && a[i] >= s.top()) {
                    res[i] += cnt.top();
                    cnt.pop();
                    s.pop();
                }
            }
        }
        for (long i = 0; i < n; i ++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}