//
// Created by khanh on 5/26/2021.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t --) {
        string str;
        cin >> str;
        stack <int> stk;
        for (int i = 0; i < str.length(); i ++) {
            if (str[i] == '+') {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y + x);
            } else if (str[i] == '-') {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y - x);
            } else if (str[i] == '*') {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(x * y);
            } else if (str[i] == '/') {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y / x);
            } else {
                stk.push((int) (str[i] - '0'));
            }
        }
        cout << stk.top();
        cout << endl;
    }
    return 0;
}