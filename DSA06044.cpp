//
// Created by KhanhNVTB on 13/05/2021.
//

#include<bits/stdc++.h>
using namespace std;
main() {
    long n;
    cin >> n;
    long a[n];
    vector <long> chan;
    vector <long> le;
    for (long i = 0 ; i < n ; i++) {
        cin >> a[i];
        if (i % 2 == 0) {
            chan.push_back (a[i]);
        } else {
            le.push_back (a[i]);
        }
    }
    sort (le.begin (), le.end ());
    sort (chan.begin (), chan.end ());
    long k = 0, h = le.size () - 1;
    for (long i = 0 ; i < n ; i++) {
        if (i % 2 == 0) {
            cout << chan[k] << " ";
            k++;
        } else {
            cout << le[h] << " ";
            h--;
        }
    }
    return 0;
}

