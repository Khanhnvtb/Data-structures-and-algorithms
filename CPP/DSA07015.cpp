//
// Created by khanh on 5/16/2021.
//
#include <bits/stdc++.h>
using namespace std;
int comp( char x ) {
    if (x == '(') {
        return 1;
    } else if (x == '+' || x == '-') {
        return 2;
    } else if (x == '*' || x == '/') {
        return 3;
    } else {
        return 4;
    }
}
bool isOperator( char x ) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return true;
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        string str;
        cin >> str;
        stack <char> stk;
        string s = "";
        for (int i = 0; i < str.length(); i ++) {
            if (isdigit(str[i])) {
                s += str[i];
                if (i == str.length() - 1 || ! isdigit(str[i + 1])) {
                    s += '.';
                }
            } else if (str[i] == '(') {
                stk.push(str[i]);
            } else if (str[i] == ')') {
                while (stk.size() > 0 && stk.top() != '(') {
                    s += stk.top();
                    stk.pop();
                }
                stk.pop();
            } else {
                while (stk.size() > 0 && comp(stk.top()) >= comp(str[i])) {
                    s += stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
            }
        }
        while (stk.size() > 0 && stk.top() != '(') {
            s += stk.top();
            stk.pop();
        }
        long val = 0;
        stack <long> st;
        for (int i = 0; i < s.length(); i ++) {
            if (isOperator(s[i])) {
                long x = st.top();
                st.pop();
                long y = st.top();
                st.pop();
                if (s[i] == '+') {
                    st.push(y + x);
                } else if (s[i] == '-') {
                    st.push(y - x);
                } else if (s[i] == '*') {
                    st.push(y * x);
                } else {
                    st.push(y / x);
                }
            } else if (s[i] == '.') {
                st.push(val);
                val = 0;
            } else {
                val = val * 10 + (s[i] - 48);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}
