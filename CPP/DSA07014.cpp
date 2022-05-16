//
// Created by KhanhNVTB on 12/05/2021.
//

#include <bits/stdc++.h>
using namespace std;
string str;
void init() {
    cin >> str;
}
void solve() {
    stack <int> s;
    for (int i = str.length() - 1; i >= 0; i --) {
        if (str[i] == '+') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(x + y);
        } else if (str[i] == '-') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(x - y);
        } else if (str[i] == '*') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(x * y);
        } else if (str[i] == '/') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(x / y);
        } else {
            s.push((int) (str[i] - '0'));
        }
    }
    cout << s.top() << endl;
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
