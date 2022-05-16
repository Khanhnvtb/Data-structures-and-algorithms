//
// Created by KhanhNVTB on 14/05/2021.
//
#include <bits/stdc++.h>
using namespace std;
int n;
bool check(string s) {
    long long tmp = 0;
    for (int i = 0 ; i < s.length () ; i++) {
        tmp = tmp * 10 + (s[i] - 48);
        tmp %= n;
    }
    if (tmp == 0) {
        return true;
    } else {
        return false;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        queue <string> s;
        s.push ("1");
        while (1) {
            string res = s.front ();
            s.pop ();
            if (check (res)) {
                cout << res << "\n";
                break;
            }
            s.push (res + "0");
            s.push (res + "1");
        }
    }
    return 0;
}
