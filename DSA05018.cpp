//
// Created by khanh on 5/29/2021.
//

#include <bits/stdc++.h>
using namespace std;
string str;
int n, l, r, res;
void init() {
    cin.ignore();
    cin >> str;
    n = str.length();
    res = 1;
}
void solve() {
    for (int i = 0; i < n; i ++) {
        l = i, r = i;
        while (l > 0 && r < n - 1) {
            l --;
            r ++;
            if (str[l] != str[r]) {
                l ++;
                r --;
                break;
            }
        }
        res = max(res, r - l + 1);
    }
    for (int i = 0; i < n - 1; i ++) {
        if (str[i] == str[i + 1]) {
            l = i, r = i + 1;
            while (l > 0 && r < n - 1) {
                l --;
                r ++;
                if (str[l] != str[r]) {
                    l ++;
                    r --;
                    break;
                }
            }
            res = max(res, r - l + 1);
        }
    }
}
void print() {
    cout << res << endl;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        init();
        solve();
        print();
    }
    return 0;
}