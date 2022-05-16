//
// Created by khanh on 5/20/2021.
//

#include<bits/stdc++.h>
using namespace std;
main() {
    int t;
    cin >> t;
    while (t --) {
        long n;
        cin >> n;
        long a[n];
        for (long i = 0; i < n; i ++) {
            cin >> a[i];
        }
        long max = LONG_MIN;
        long count = 2;
        int check = 0;
        for (long i = 1; i < n; i ++) {
            if (a[i] > a[i - 1] && check == 0) {
                check = 1;
            } else if (a[i] > a[i - 1] && check == 1) {
                count ++;
            } else if (a[i] > a[i - 1] && check == 2) {
                if (count > max) {
                    max = count;
                }
                check = 1;
                count = 2;
            } else if (a[i] < a[i - 1] && check == 1) {
                count ++;
                check = 2;
            } else if (a[i] < a[i - 1] && check == 2) {
                count ++;
            }
        }
        if (count > max) {
            max = count;
        }
        cout << max << "\n";
    }
    return 0;
}