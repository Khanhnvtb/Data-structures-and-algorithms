//
// Created by khanhnvtb on 18/06/2021.
//
/* Ý tưởng: 
*/
//khuyến khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        set <int> s;
        set <int>::iterator it;
        int n, a, b;
        char c;
        cin >> n >> a >> b >> c;
        s.insert (a);
        s.insert (b);
        for (int i = 1; i < n; i++) {
            cin >> a >> b >> c;
            s.insert (b);
        }
        for (it = s.begin (); it != s.end (); it++) cout << *it << " ";
        cout << endl;
    }
    return 0;
}