//
// Created by khanh on 5/16/2021.
//

#include <bits/stdc++.h>
using namespace std;
int cnt;
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);
        cnt = 0;
        stack<int> s;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                cnt++;
                s.push(cnt);
                cout << cnt << " ";
            } else if (str[i] == ')') {
                cout << s.top() << " ";
                s.pop();
            }
        }
        cout << endl;
    }
    return 0;
}