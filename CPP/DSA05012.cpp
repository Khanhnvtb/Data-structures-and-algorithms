//
// Created by khanh on 5/26/2021.
//

#include <bits/stdc++.h>
using namespace std;
long m=1e9+7;
class Tohop {
public:
    int t, n, k;
    long a[1001][1001];

    void solve() {
        for (int i = 1; i <= 1000; i ++) {
            a[1][i] = i;
        }
        for (int i = 2; i <= 1000; i ++) {
            for (int j = 2; j <= i; j ++) {
                a[j][i] = (a[j][i - 1] % m + a[j - 1][i - 1] % m) % m;
            }
        }
    }

    void output() {
        cout << a[k][n];
        cout << endl;
    }

    void input() {
        cin >> this->t;
        while (t --) {
            cin >> this->n >> this->k;
            output();
        }
    }
};
int main() {
    Tohop obj;
    obj.solve();
    obj.input();
    return 0;
}