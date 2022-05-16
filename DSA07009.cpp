//
// Created by khanh on 5/16/2021.
//

#include <bits/stdc++.h>
using namespace std;
bool isOperator(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return true;
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);
        stack<string> s;
        for (int i = str.length() - 1; i >= 0; i--) {
            if (isOperator(str[i])) {
                string str1 = s.top();
                s.pop();
                string str2 = s.top();
                s.pop();
                string tmp = "(" + str1 + str[i] + str2 + ")";
                s.push(tmp);
            } else {
                string tmp = "";
                s.push(tmp + str[i]);
            }
        }
        cout << s.top() << "\n";
    }
    return 0;
}