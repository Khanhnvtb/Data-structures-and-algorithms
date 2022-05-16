//
// Created by khanh on 5/30/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n;
vector <string> dp;
string mul(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    int res[n1 + n2];
    memset(res, 0, sizeof(res));
    for (int i = s1.length() - 1; i >= 0; i --) {
        for (int j = s2.length() - 1; j >= 0; j --) {
            res[i + j + 1] += (s1[i] - '0') * (s2[j] - '0');
        }
    }
    for (int i = n1 + n2 - 1; i >= 0; i --) {
        if (res[i] > 9) {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    string ans = "";
    if (res[0] != 0) {
        ans += to_string(res[0]);
    }
    for (int i = 1; i < n1 + n2; i ++) {
        ans += to_string(res[i]);
    }
    return ans;
}
string add(string s1, string s2) {
    if (s1.length() > s2.length()) {
        string tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    int n1 = s1.length();
    int n2 = s2.length();
    int res[n2 + 1];
    res[0] = 0;
    for (int i = n2 - 1; i >= n2 - n1; i --) {
        res[i + 1] = (s1[i - (n2 - n1)] - '0') + (s2[i] - '0');
    }
    for (int i = 0; i < n2 - n1; i ++) {
        res[i + 1] = (s2[i] - '0');
    }
    for (int i = n2; i > 0; i --) {
        if (res[i] > 9) {
            res[i - 1] ++;
            res[i] -= 10;
        }
    }
    string ans = "";
    if (res[0] != 0) {
        ans += to_string(res[0]);
    }
    for (int i = 1; i <= n2; i ++) {
        ans += to_string(res[i]);
    }
    return ans;
}
void init() {
    cin >> n;
}
void solve() {
    dp.push_back("1");
    for (int i = 1; i <= 100; i ++) {
        string tmp = "";
        for (int j = 0; j < i; j ++) {
            tmp = add(tmp, mul(dp[j], dp[i - j - 1]));
        }
        dp.push_back(tmp);
    }
}
void print() {
    cout << dp[n] << endl;
}
int main() {
    int t;
    cin >> t;
    solve();
    cin.ignore();
    while (t --) {
        init();
        print();
    }
    return 0;
}