//
// Created by khanh on 5/16/2021.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t --) {
        string str;
        cin >> str;
        stack <int> s;
        for (int i = 0; i < str.length(); i ++) {
            if (str[i] == '(' && i > 0) {
                s.push(i);
            } else if (str[i] == ')' && s.size()>0) {
                if (str[s.top() - 1] == '-') {
                    for (int j = s.top(); j < i; j ++) {
                        if (str[j] == '+') {
                            str[j] = '-';
                        } else if (str[j] == '-') {
                            str[j] = '+';
                        }
                    }
                }
                s.pop();
            }
        }
        for (int i = 0; i < str.length(); i ++) {
            if (str[i] != '(' && str[i] != ')') {
                cout << str[i];
            }
        }
        cout << endl;
    }
    return 0;
}
