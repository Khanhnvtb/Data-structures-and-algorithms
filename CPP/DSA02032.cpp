//
// Created by KhanhNVTB on 09/05/2021.
//

#include<bits/stdc++.h>
using namespace std;
int n, k, a[20];
int cnt;
vector <int> res;
void Try(int i, int sum, vector <int> tmp) {
    for (int j = 1 ; j >= 0 ; j--) {
        if (j == 1) {
            sum += a[i];
            tmp.push_back (a[i]);
            if (sum > k) {
                return;
            } else if (sum == k) {
                cnt++;
                for (int x = 0 ; x < tmp.size () ; x++) {
                    res.push_back (tmp[x]);
                }
                res.push_back (-1);
                return;
            } else {
                if (i < n) {
                    Try (i, sum, tmp);
                }
            }
            sum -= a[i];
            tmp.pop_back ();
        } else {
            if (i < n - 1) {
                Try (i + 1, sum, tmp);
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cnt = 0;
        res.clear();
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        vector <int> tmp;
        Try (0, 0, tmp);
        if (cnt == 0) {
            cout << "-1";
        } else {
            cout << cnt << " {";
            for (int i = 0 ; i < res.size () - 1 ; i++) {
                if (res[i] != -1 && res[i + 1] != -1) {
                    cout << res[i] << " ";
                } else if (res[i] != -1 && res[i + 1] == -1) {
                    cout << res[i];
                } else {
                    cout << "} {";
                }
            }
            cout << "}";
        }
        cout << endl;
    }
    return 0;
}