//
// Created by KhanhNVTB on 09/05/2021.
//
#include <bits/stdc++.h>
using namespace std;
long n;
int res;
void Try(long n,int cnt) {
    for (int i = 0 ; i < 2 ; i++) {
        if (i == 0) {
            if (n % 3 == 0) {
                n /= 3;
                cnt++;
                if (cnt > res) {
                    return;
                }
                if (n > 1) {
                    Try (n, cnt);
                } else {
                    res = min (res, cnt);
                }
                n *= 3;
                cnt--;
            } else {
                n--;
                cnt++;
                if (cnt > res) {
                    return;
                }
                if (n > 1) {
                    Try (n, cnt);
                } else {
                    res = min (res, cnt);
                }
                n++;
                cnt--;
            }
        } else {
            if (n % 2 == 0) {
                n /= 2;
                cnt++;
                if (cnt > res) {
                    return;
                }
                if (n > 1) {
                    Try (n, cnt);
                } else {
                    res = min (res, cnt);
                }
                n *= 2;
                cnt--;
            } else {
                n--;
                cnt++;
                if (cnt > res) {
                    return;
                }
                if (n > 1) {
                    Try (n, cnt);
                } else {
                    res = min (res, cnt);
                }
                n++;
                cnt--;
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        res = INT_MAX;
        Try (n, 0);
        cout << res << "\n";
    }
    return 0;
}
