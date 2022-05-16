//
// Created by khanh on 5/27/2021.
//
#include<bits/stdc++.h>
using namespace std;
int n, res, a[10], b[10]={0}, repeat[10][10];
vector <string> v;
int find(string s1, string s2) {
    int pos = 0;
    int cnt = 0;
    for (int i = 0; i < s1.length(); i ++) {
        for (int j = pos; j < s2.length(); j ++) {
            if (s1[i] == s2[j]) {
                cnt ++;
                pos = j + 1;
                break;
            } else if (s1[i] < s2[j]) {
                j = pos;
                break;
            }
        }
    }
    return cnt;
}
void Try(int k) {
    for (int i = 0; i < n; i ++) {
        if (b[i] == 0) {
            a[k] = i;
            b[i] = 1;
            if (k == n - 1) {
                int cnt = 0;
                for (int i = 0; i < n - 1; i ++) {
                    cnt += repeat[a[i]][a[i + 1]];
                }
                if (cnt < res) {
                    res = cnt;
                }
            } else {
                Try(k + 1);
            }
            b[i] = 0;
        }
    }
}
int main() {
    cin >> n;
    res = INT_MAX;
    for (int i = 0; i < n; i ++) {
        cin.ignore();
        string str;
        cin >> str;
        v.push_back(str);
    }
    for (int i = 0; i < n - 1; i ++) {
        for (int j = i + 1; j < n; j ++) {
            repeat[i][j] = find(v[i], v[j]);
            repeat[j][i] = find(v[i], v[j]);
        }
    }
    Try(0);
    cout << res << endl;
    return 0;
}
