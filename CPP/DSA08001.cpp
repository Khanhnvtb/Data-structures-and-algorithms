//
// Created by KhanhNVTB on 12/05/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        queue <int> q;
        while (n--) {
            int x;
            cin >> x;
            switch (x) {
                case 1:
                    cout << q.size () << "\n";
                    break;
                case 2:
                    if (q.size ()) {
                        cout << "NO" << "\n";
                    } else {
                        cout << "YES" << "\n";
                    }
                    break;
                case 3:
                    int y;
                    cin >> y;
                    q.push (y);
                    break;
                case 4:
                    if (q.size ()) {
                        q.pop ();
                    }
                    break;
                case 5:
                    if (q.size ()) {
                        cout << q.front () << "\n";
                    } else {
                        cout << -1 << "\n";
                    }
                    break;
                case 6:
                    if (q.size ()) {
                        cout << q.back () << endl;
                    } else {
                        cout << -1 << endl;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}