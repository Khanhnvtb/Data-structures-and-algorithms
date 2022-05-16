//
// Created by khanh on 5/22/2021.
//

#include <bits/stdc++.h>
using namespace std;
string convert(string str) {
    stack <int> s;
    string tmp = "";
    for (int i = 0; i < str.length(); i ++) {
        if (str[i] == '(' && i > 0) {
            s.push(i);
        } else if (str[i] == ')' && s.size() > 0) {
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
            tmp += str[i];
        }
    }
    return tmp;
}
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t --) {
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        if (convert(str1) == convert(str2)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}