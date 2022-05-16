//
// Created by khanh on 5/16/2021.
//
#include <bits/stdc++.h>
using namespace std;
string str;
deque<int> q;
int n;
void init() {
    cin >> str;
}
void solve() {
    if (str == "PUSHBACK") {
        cin >> n;
        q.push_back(n);
    } else if (str == "PUSHFRONT") {
        cin >> n;
        q.push_front(n);
    } else if (str == "PRINTFRONT") {
        if (q.size() > 0) {
            cout << q.front() << "\n";
        } else {
            cout << "NONE" << "\n";
        }
    } else if (str == "POPFRONT") {
        if (q.size() > 0) {
            q.pop_front();
        }
    } else if (str == "PRINTBACK") {
        if (q.size() > 0) {
            cout << q.back() << "\n";
        } else {
            cout << "NONE" << "\n";
        }
    } else if (str == "POPBACK") {
        if (q.size() > 0) {
            q.pop_back();
        }
    }
}
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t --) {
        init();
        solve();
    }
    return 0;
}
