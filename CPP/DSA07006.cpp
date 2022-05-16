//
// Created by khanhnvtb on 15/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

set <string> s;
set <string>::iterator it;
int n, cnt, a[10];
string str, tmp;
vector <pair <int, int> > v;

void init() {
    cin >> str;
    n = str.length () - 1;
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == cnt - 1) {
            bool used[205] = {0};
            for (int t = 0; t < cnt; t++) {
                if (a[t] == 0) {
                    used[v[t].first] = 1;
                    used[v[t].second] = 1;
                }
            }
            string tmp = "";
            for (int t = 0; t <= n; t++) {
                if (used[t] == 0) {
                    tmp += str[t];
                }
            }
            s.insert (tmp);
        } else Try (i + 1);
    }
}

void solve() {
    stack <int> st;
    cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (str[i] == '(') {
            cnt++;
            st.push (i);
        } else if (str[i] == ')') {
            v.push_back ({st.top (), i});
            st.pop ();
        }
    }
    sort (v.begin (), v.end ());
    Try (0);
    s.erase (s.begin ());
    for (it = s.begin (); it != s.end (); it++) {
        cout << *it << endl;
    }
}

int main() {
    init ();
    solve ();
    return 0;
}