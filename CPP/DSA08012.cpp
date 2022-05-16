//
// Created by khanh on 5/21/2021.
//
#include <bits/stdc++.h>
using namespace std;
long l, r;
int test(string s) {
    int used[10];
    memset(used,0,sizeof(used));
    for (int i = 0; i < s.length(); i ++) {
        int tmp = (int)(s[i]-'0');
        if (used[tmp] == 0) {
            used[tmp] = 1;
        } else {
            return 0;
        }
    }
    return 1;
}
int main() {
    int t;
    cin >> t;
    queue <string> q;
    vector <long> a;
    q.push("1");
    q.push("2");
    q.push("3");
    q.push("4");
    q.push("5");
    while (!q.empty) {
        string tmp = q.front();
        q.pop();
        if (tmp.length() > 5) {
            break;
        }
        long y = 0;
        for (int i = 0; i < tmp.length(); i ++) {
            y = y * 10 + (tmp[i] - 48);
        }
        a.push_back(y);
        for (int i = 0; i <= 5; i ++) {
            char x = i+48;
            if (test(tmp + x) == 1) {
                q.push(tmp + x);
            }
        }
    }
    while (t --) {
        cin >> l >> r;
        if (l == 0 && r == 0 || l == 1e5 & r == 1e5) {
            cout << "0" << "\n";
        } else {
            long x = 0, y = a.size() - 1;
            while (a[x] < l && x < a.size()) {
                x ++;
            }
            while (a[y] > r && y > 0) {
                y --;
            }
            cout << y - x + 1 << "\n";
        }
    }
    return 0;
}
