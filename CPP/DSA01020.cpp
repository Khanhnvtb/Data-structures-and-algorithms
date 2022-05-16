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
        int check = 0;
        for (int i = str.length() - 1; i >= 0; i --) {
            if (str[i] == '1') {
                str[i] = '0';
                check = 1;
                for (int j = i + 1; j < str.length(); j ++) {
                    str[j] = '1';
                }
                break;
            }
        }
        if (check == 0) {
            for (int i = 0; i < str.length(); i ++) {
                cout << "1";
            }
        } else {
            cout << str;
        }
        cout << endl;
    }
    return 0;
}
