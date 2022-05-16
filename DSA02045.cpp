//
// Created by khanh on 5/26/2021.
//

#include<bits/stdc++.h>
using namespace std;
string str;
int n;
void Try(int i,vector<int>res) {
    for (int j = 1; j >= 0; j --) {
        if (j == 1) {
            res.push_back(i);
            for (int k = 0; k < res.size(); k ++) {
                cout << str[res[k]];
            }
            cout << " ";
            if (i < n - 1) {
                Try(i + 1, res);
            }
            res.pop_back();
        } else {
            if (i < n - 1) {
                Try(i + 1, res);
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        cin >> str;
        sort(str.begin(), str.end());
        vector <int> res;
        Try(0, res);
        cout << endl;
    }
    return 0;
}