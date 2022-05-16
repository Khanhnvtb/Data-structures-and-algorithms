//
// Created by khanhnvtb on 08/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> a[1005];
void init() {
    cin >> n;
    int x, y;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        a[x].push_back (y);
    }
}
void solve() {
    for (int i = 1; i <= n; i++) {
        sort (a[i].begin (), a[i].end ());
    }
    queue <int> q;
    q.push (1);
    int prev[n + 1];
    memset (prev, 0, sizeof (prev));
    vector <int> res;
    while (!q.empty ()) {
        int u = q.front ();
        q.pop ();
        if (a[u].size () == 0) res.push_back (u);
        else {
            for (int i = 0; i < a[u].size (); i++) {
                int tmp = a[u][i];
                prev[tmp] = u;
                q.push (tmp);
            }
        }
    }
    sort (res.begin (), res.end ());
    for (int i = 0; i < res.size (); i++) {
        stack <int> s;
        int tmp = res[i];
        while (tmp != 0) {
            s.push (tmp);
            tmp = prev[tmp];
        }
        while (!s.empty ()) {
            cout << s.top () << " ";
            s.pop ();
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        a[i].clear ();
    }
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