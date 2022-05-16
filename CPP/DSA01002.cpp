//
// Created by khanh on 5/26/2021.
//

#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t --) {
        int n, k;
        cin >> n >> k;
        int a[k + 1];
        for (int i = 1; i <= k; i ++) {
            cin >> a[i];
        }
        int check = 0;
        for (int i = k; i > 0; i --) {
            if (a[i] != n - k + i) {
                a[i] = a[i] + 1;
                for (int j = i + 1; j <= k; j ++) {
                    a[j] = a[i] + j - i;
                }
                check = 1;
                break;
            }
        }
        if (check == 0) {
            for (int i = 0; i < k; i ++) {
                cout << i + 1 << " ";
            }
            cout << endl;
        } else {
            for (int i = 1; i <= k; i ++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}