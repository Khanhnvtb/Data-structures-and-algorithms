//
// Created by khanh on 5/15/2021.
//
#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main() {
    int n;
    cin >> n;
    vector<int> res[n + 1];
    for (int i = 1; i <= n; i++) {
        res[i].push_back(0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                res[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout<<endl;
    }
    cout << endl;
}



