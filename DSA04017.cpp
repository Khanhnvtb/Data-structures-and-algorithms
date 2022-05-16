#include<bits/stdc++.h>
using namespace std;
long n;
long find(long x, long y,long long a[], long long b[]) {
    long z = (x + y) / 2;
    if (a[z] == b[z]) {
        return find (z + 1, y, a, b);
    } else if (a[z] != b[z] && a[z - 1] == b[z - 1]) {
        return z;
    }
    return find (x, z - 1, a, b);
}
main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        long long a[n + 1];
        long long b[n + 1];
        for (long i = 1 ; i <= n ; i++) {
            cin >> a[i];
        }
        for (long i = 1 ; i < n ; i++) {
            cin >> b[i];
        }
        b[n] = 0;
        cout << find (1, n, a, b) << "\n";
    }
    return 0;
}
