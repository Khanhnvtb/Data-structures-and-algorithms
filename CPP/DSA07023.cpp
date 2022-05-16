//
// Created by KhanhNVTB on 11/05/2021.
//
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    cin.ignore ();
    while (t--) {
        string str;
        getline (cin, str);
        stack <string> stk;
        string s = "";
        for (int i = 0 ; i < str.length () ; i++) {
            if (str[i] != ' ') {
                s += str[i];
            } else {
                stk.push (s);
                s = "";
            }
        }
        stk.push(s);
        while (!stk.empty ()) {
            cout << stk.top () << " ";
            stk.pop ();
        }
        cout << endl;
    }
    return 0;
}
