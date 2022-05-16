//
// Created by khanh on 5/18/2021.
//

#include<bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;
    deque <char> q;
    stack <char> s;
    string res = "";
    for (long long i = 0; i < str.length(); i ++) {
        if (str[i] == '-' && ! q.empty()) {
            q.pop_back();
        } else if (! q.empty() > 0 && str[i] == '<') {
            s.push(q.back());
            q.pop_back();
        } else if (! s.empty() && str[i] == '>') {
            q.push_back(s.top());
            s.pop();
        } else if (str[i] != '-' && str[i] != '<' && str[i] != '>') {
            q.push_back(str[i]);
        }
    }
    while (! q.empty()) {
        res += q.front();
        q.pop_front();
    }
    while (! s.empty()) {
        res += s.top();
        s.pop();
    }
    cout << res;
    return 0;
}