//
// Created by khanh on 5/16/2021.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);
        stack<char> s;
        int check = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ')') {
                if (s.top() == '(') {
                    check = 1;
                    break;
                } else {
                    while (s.top() != '(') {
                        s.pop();
                    }
                    s.pop();
                }
            } else if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
                s.push(str[i]);
            }
        }
        if (check) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    return 0;
}
