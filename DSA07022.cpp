//
// Created by khanh on 5/29/2021.
//

#include <bits/stdc++.h>
using namespace std;
long n, a[100000], cnt[1000000];
vector <long> res;
void init() {
    res.clear();
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (long i = 0; i < n; i ++) {
        cin >> a[i];
        cnt[a[i]] ++;
    }
}
void solve() {
    stack <long> s;
    s.push(a[n - 1]);
    for (long i = n - 1; i >= 0; i --) {
        while (! s.empty() && cnt[s.top()] <= cnt[a[i]]) {
            s.pop();
        }
        if (! s.empty()) {
            res.push_back(s.top());
        } else {
            res.push_back(- 1);
        }
        s.push(a[i]);
    }
}
void print() {
    for (long i = res.size() - 1; i >= 0; i --) {
        cout << res[i] << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        init();
        solve();
        print();
    }
    return 0;
}