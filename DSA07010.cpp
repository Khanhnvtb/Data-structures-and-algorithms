//
// Created by khanh on 5/16/2021.
//

#include <bits/stdc++.h>
using namespace std;
string str;
bool isOperator(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return true;
    }
    return false;
}
void init() {
    getline(cin, str);
}
void solve() {
    stack <string> s;
    for (int i = str.length() - 1; i >= 0; i --) {
        if (isOperator(str[i])) {
            string str1 = s.top();
            s.pop();
            string str2 = s.top();
            s.pop();
            string tmp = str1 + str2 + str[i];
            s.push(tmp);
        } else {
            string tmp = "";
            s.push(tmp + str[i]);
        }
    }
    cout << s.top() << endl;
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
