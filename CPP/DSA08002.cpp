//
// Created by KhanhNVTB on 13/05/2021.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    queue <int> a;
    while (t--) {
        string s;
        cin >> s;
        if (s == "PUSH") {
            int x;
            cin >> x;
            a.push (x);
        } else if (s == "POP") {
            if (a.size()>0) {
                a.pop ();
            }
        } else {
            if (a.size()>0) {
                cout << a.front () << " ";
            } else {
                cout << "NONE";
            }
            cout << endl;
        }
    }
    return 0;
}