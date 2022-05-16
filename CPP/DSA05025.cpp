//
// Created by khanh on 5/26/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n;
vector <long> res;
int main() {
    int t;
    cin >> t;
    res.push_back(1), res.push_back(1), res.push_back(2);
    while (t --) {
        cin >> n;
        for (int i = res.size(); i <= n; i ++) {
            long tmp = 0;
            tmp += res[i - 1] + res[i - 2] + res[i - 3];
            res.push_back(tmp);
        }
        cout << res[n] << "\n";
    }
    return 0;
}