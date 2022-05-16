//
// Created by KhanhNVTB on 12/05/2021.
//

#include <bits/stdc++.h>
using namespace std;
long n, a[100005];
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (long i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        long long res = 0, x, y, mul;
        long i = 0;
        stack <long> s;
        while (i < n) {
            if (s.size () == 0 || a[s.top ()] <= a[i]) {
                s.push (i);
                i++;
            } else {
                x = s.top ();
                s.pop ();
                if (s.size () > 0) {
                    y = s.top ();
                }
                mul = a[x] * (s.empty () ? i : i - y - 1);
                res = max (res, mul);
            }
        }
        while (s.size () > 0) {
            x = s.top ();
            s.pop ();
            if (s.size ())
                y = s.top ();
            mul = a[x] * (s.empty () ? i : i - y - 1);
            res = max (res, mul);
        }
        cout << res << "\n";
    }
    return 0;
}