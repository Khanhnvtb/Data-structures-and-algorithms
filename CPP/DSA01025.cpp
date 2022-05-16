//
// Created by KhanhNVTB on 14/05/2021.
//
#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[20];
void Try(int i, int cnt) {
    for (int j = 1 ; j >= 0 ; j--) {
        if (j == 1) {
            cnt++;
            a[cnt] = i;
            if (cnt == k) {
                for (int i = 1 ; i <= k ; i++) {
                    char tmp = a[i];
                    cout << tmp;
                }
                cout << endl;
            } else if (cnt < k) {
                if (i < 64 + n) {
                    Try (i + 1, cnt);
                }
            } else {
                return;
            }
            cnt--;
        } else {
            if (i < 64 + n) {
                Try (i + 1, cnt);
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        Try (65, 0);
    }
    return 0;
}
