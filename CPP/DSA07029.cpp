//
// Created by khanh on 5/17/2021.
//
#include <bits/stdc++.h>
using namespace std;
string str;
void init() {
    getline(cin, str);
}
void solve() {
    int val = 0;
    string tmp = "";
    stack <int> s;
    stack <string> stk;
    string res = "";
    for (int i = 0; i < str.length(); i ++) {
        if (isdigit(str[i])) {
            val = val * 10 + (str[i] - 48);
        } else if (isalpha(str[i])) {
            tmp += str[i];
            if (! isalpha(str[i + 1])) {
                stk.push(tmp);
                tmp = "";
            }
        } else if (str[i] == '[') {
            if (val != 0) {
                s.push(val);
            } else {
                s.push(1);
            }
            val = 0;
        } else if (str[i] == ']') {
            int x = s.top();
            while (x --) {
                tmp += stk.top();
            }
            stk.pop();
            string a = "";
            if (! stk.empty()) {
                a += stk.top();
                stk.pop();
            }
            a += tmp;
            stk.push(a);
            s.pop();
            tmp = "";
            if (s.size() == 0) {
                res += stk.top();
                stk.pop();
            }
        }
    }
    cout << res << endl;
}
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t --) {
        init();
        solve();
    }
    return 0;
}
