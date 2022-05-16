#include<bits/stdc++.h>
using namespace std;
int a[100];
int b[100][100];
int res=0;
bool ktra(int x, int y) {
    for (int i = 1 ; i < x ; i++) {
        if (a[i] == y || abs (i - x) == abs (a[i] - y)) {
            return false;
        }
    }
    return true;
}
void Try(int i) {
    for (int j = 1 ; j <= 8 ; j++) {
        if (ktra (i, j)) {
            a[i] = j;
            if (i == 8) {
                int sum = 0;
                for (int k = 1 ; k <= 8 ; k++) {
                    sum += b[k][a[k]];
                }
                if (sum > res) {
                    res = sum;
                }
            }
            Try (i + 1);
        }
    }
}
main() {
    int t;
    cin >> t;
    while (t--) {
        res=0;
        for (int i = 1 ; i <= 8 ; i++) {
            for (int j = 1 ; j <= 8 ; j++) {
                cin >> b[i][j];
            }
        }
        Try (1);
        cout << res << "\n";
    }
    return 0;
}