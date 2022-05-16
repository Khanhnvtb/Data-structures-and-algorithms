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
        string str1;
        getline(cin, str1);
        string str2;
        getline(cin, str2);
        stack <int> s;
        int val = 0;
        vector <int> a[10005];
        int degmax, degmin;
        for (int i = 0; i < str1.length(); i ++) {
            if (str1[i] >= 48 && str1[i] <= 57) {
                val = val * 10 + (str1[i] - 48);
            } else if (str1[i] == '+' || str1[i] == '*') {
                s.push(val);
                val = 0;
            }
        }
        s.push(val);
        degmin = s.top();
        val = 0;
        for (int i = 0; i < str1.length(); i ++) {
            if (str1[i] >= 48 && str1[i] <= 57) {
                val = val * 10 + (str1[i] - 48);
            } else if (str1[i] == '+') {
                degmax = val;
                val = 0;
                break;
            } else if (str1[i] == '*') {
                val = 0;
            }
        }
        for (int i = 0; i < str2.length(); i ++) {
            if (str2[i] >= 48 && str2[i] <= 57) {
                val = val * 10 + (str2[i] - 48);
            } else if (str2[i] == '+' || str2[i] == '*') {
                s.push(val);
                val = 0;
            }
        }
        s.push(val);
        degmin = min(degmin, s.top());
        val = 0;
        for (int i = 0; i < str2.length(); i ++) {
            if (str2[i] >= 48 && str2[i] <= 57) {
                val = val * 10 + (str2[i] - 48);
            } else if (str2[i] == '+') {
                degmax = max(degmax, val);
                val = 0;
                break;
            } else if (str2[i] == '*') {
                val = 0;
            }
        }
        while (! s.empty()) {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            a[x].push_back(y);
        }
        for (int i = degmax; i >= degmin; i --) {
            if (a[i].size() > 0) {
                val = 0;
                for (int j = 0; j < a[i].size(); j ++) {
                    val += a[i][j];
                }
                cout << val << "*x^" << i;
                if (i != degmin) {
                    cout << " + ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
