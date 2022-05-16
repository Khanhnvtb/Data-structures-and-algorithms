//
// Created by khanh on 5/16/2021.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        long a[n];
        for (long i = 0; i < n; i++) {
            cin >> a[i];
        }
        stack<long> s;
        long res[n];
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[i] >= s.top()) {
                s.pop();
            }
            if (s.empty()) {
                res[i] = -1;
            } else {
                res[i] = s.top();
            }
            s.push(a[i]);
        }
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
