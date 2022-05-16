//
// Created by khanh on 5/17/2021.
//
#include<bits/stdc++.h>
using namespace std;
int res;
int main() {
    int t;
    cin >> t;
    while (t --) {
        string str;
        cin >> str;
        res = 0;
        stack <char> s;
        for (int i = 0; i < str.length(); i ++) {
            if (str[i] == '(') {
                s.push(str[i]);
            } else {
                if (! s.empty()) {
                    res += 2;
                    s.pop();
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
