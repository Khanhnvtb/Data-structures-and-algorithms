//
// Created by khanh on 5/17/2021.
//

#include<bits/stdc++.h>
using namespace std;
int n;
char a[20];
void in() {
    for (int i = 1; i <= n; i ++) {
        cout << a[i];
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        if (n == 2) {
            cout << "HA" << "\n";
        } else if (n == 3) {
            cout << "HAA" << "\n";
        } else {
            a[1] = 'H', a[2] = 'A', a[n] = 'A';
            for (int i = 3; i < n; i ++) {
                a[i] = 'A';
            }
            in();
            for (int i = n - 1; i >= 3; i --) {
                if (a[i] == 'A') {
                    a[i] = 'H';
                    for (int j = i + 1; j < n; j ++) {
                        a[j] = 'A';
                    }
                    int check = 1;
                    for (int i = 2; i < n - 1; i ++) {
                        if (a[i] == 'H' && a[i + 1] == 'H') {
                            check = 0;
                            break;
                        }
                    }
                    if (check) {
                        in();
                    }
                    i = n;
                }
            }
        }
    }
    return 0;
}