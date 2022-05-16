//
// Created by khanhnvtb on 07/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;
string str;
void init() {
    cin >> str;
}
void solve() {
    string res;
    stack <int> s;
    for (int i = 0; i <= str.length (); i++) {
        s.push (i + 1);
        if (i == str.length () || str[i] == 'I') {
            while (!s.empty ()) {
                res += to_string (s.top ());
                s.pop ();
            }
        }
    }
    cout << res << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}