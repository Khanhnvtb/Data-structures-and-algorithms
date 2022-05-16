//
// Created by KhanhNVTB on 11/05/2021.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    stack <int> stk;
    while (cin >> s) {
        if (s == "push") {
            int n;
            cin >> n;
            stk.push (n);
        } else if (s == "pop") {
            stk.pop ();
        } else {
            if (stk.size () == 0) {
                cout << "empty" << "\n";
            } else {
                vector <int> res;
                while (!stk.empty ()) {
                    res.push_back (stk.top ());
                    stk.pop ();
                }
                for (int i = res.size () - 1 ; i >= 0 ; i--) {
                    cout << res[i] << " ";
                    stk.push (res[i]);
                }
                cout << endl;
            }
        }
    }
    return 0;
}
