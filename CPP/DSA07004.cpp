//
// Created by khanh on 5/21/2021.
//
#include <bits/stdc++.h>
using namespace std;
string str;
int res;
void init() {
    cin >> str;
}
void solve() {
    stack <char> s;
    res = 0;
    for (int i = 0; i < str.length(); i ++) {
        if (s.empty() && str[i] == ')') {
            res ++;
            s.push('(');
        } else if (! s.empty() && str[i] == ')') {
            s.pop();
        } else {
            s.push('(');
        }
    }
    res += s.size() / 2;
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
