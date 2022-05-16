//
// Created by khanh on 04/06/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
void init() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    int bg[n];
    int sm[n];
    stack <int> s;
    for (int i = n - 1; i >= 0; i --) {
        while (! s.empty() && a[i] >= a[s.top()]) {
            s.pop();
        }
        if (! s.empty()) {
            bg[i] = s.top();
        } else {
            bg[i] = - 1;
        }
        s.push(i);
    }
    while (! s.empty()) s.pop();
    for (int i = n - 1; i >= 0; i --) {
        while (! s.empty() && a[i] <= a[s.top()]) {
            s.pop();
        }
        if (! s.empty()) {
            sm[i] = s.top();
        } else {
            sm[i] = - 1;
        }
        s.push(i);
    }
    for (int i = 0; i < n; i ++) {
        if (bg[i] != - 1 && sm[bg[i]] != - 1) {
            cout << a[sm[bg[i]]] << " ";
        } else {
            cout << "-1" << " ";
        }
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        init();
        solve();
    }
    return 0;
}