//
// Created by KhanhNVTB on 13/05/2021.
//

#include<bits/stdc++.h>
using namespace std;
vector <long long> res;
long long tmp [100005];
void nhap( long n, long long a[] ) {
    for (long i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
}
void intersect( long n1, long long a[], long n2, long long b[] ) {
    long x = 0;
    for (long i = 0 ; i < n1 ; i++) {
        for (long j = x ; j < n2 ; j++) {
            if (a[i] == b[j]) {
                res.push_back (a[i]);
                x = j + 1;
                break;
            } else if (a[i] < b[j]) {
                x = j;
                break;
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        res.clear ();
        long n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        long long a[n1], b[n2], c[n3];
        nhap (n1, a);
        nhap (n2, b);
        nhap (n3, c);
        intersect (n1, a, n2, b);
        if (res.size () == 0) {
            cout << "-1" << "\n";
        } else {
            long k = 0;
            for (long i = 0 ; i < res.size () ; i++) {
                tmp[k++] = res[i];
            }
            res.clear ();
            intersect (k, tmp, n3, c);
            if (res.size () == 0) {
                cout << "-1" << "\n";
            } else {
                for (long i = 0 ; i < res.size () ; i++) {
                    cout << res[i] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}