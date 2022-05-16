//
// Created by KhanhNVTB on 14/05/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n;
int used[10];
int a[10];
int b[10];
void sinhso(int i) {
    for (int j = 1 ; j <= n ; j++) {
        b[i] = j;
        if (i == n) {
            for (int x = 1 ; x <= n ; x++) {
                char tmp = a[x] + 64;
                cout << tmp;
            }
            for (int tmp = 1 ; tmp <= n ; tmp++) {
                cout << b[tmp];
            }
            cout << endl;
        } else {
            sinhso (i + 1);
        }
    }
}
void Try(int i) {
    for (int j = 1 ; j <= n ; j++) {
        if (used[j] == 0) {
            used[j] = 1;
            a[i] = j;
            if (i == n) {
                sinhso (1);
            } else {
                Try (i + 1);
            }
            used[j] = 0;
        }
    }
}
int main() {
    cin >> n;
    memset (used, 0, sizeof (used));
    Try (1);
    return 0;
}