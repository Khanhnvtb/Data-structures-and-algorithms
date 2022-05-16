//
// Created by khanh on 5/22/2021.
//

#include <bits/stdc++.h>
using namespace std;
int S, T, l, r;
int vs[1100];
vector <int> b[2000];
bool compare(int num1, int num2){
    string s1 = to_string(num1);
    string s2 = to_string(num2);
    int c = 0;
    if (s1[0] != s2[0])
        c++;
    if (s1[1] != s2[1])
        c++;
    if (s1[2] != s2[2])
        c++;
    if (s1[3] != s2[3])
        c++;
    return (c == 1);
}
int bfs(int u) {
    queue <int> q;
    vs[u] = 1;
    q.push(u);
    while (! q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = 0; i < b[p].size(); i ++) {
            int tmp = b[p][i];
            if (! vs[tmp]) {
                vs[tmp] = vs[p] + 1;
                q.push(tmp);
            }
            if (tmp == r) {
                return vs[tmp] - 1;
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    vector <int> a;
    bool isPrime[10000] = {false};
    for (int i = 2; i < 10000; i ++) {
        if (isPrime[i] == false) {
            for (int j = i * i; j <= 10000; j += i) {
                isPrime[j] = true;
            }
        }
    }
    for (int i = 1000; i < 10000; i ++) {
        if (! isPrime[i]) {
            a.push_back(i);
        }
    }
    for (int i = 0; i < a.size(); i ++) {
        for (int j = i + 1; j < a.size(); j ++) {
            if (compare(a[i], a[j]) == 1) {
                b[i].push_back(j);
                b[j].push_back(i);
            }
        }
    }
    while (t --) {
        cin >> S >> T;
        memset(vs, 0, sizeof(vs));
        for (int i = 0; i < a.size(); i ++) {
            if (S == a[i]) {
                l = i;
                break;
            }
        }
        for (int i = 0; i < a.size(); i ++) {
            if (T == a[i]) {
                r = i;
                break;
            }
        }
        if (l != r) {
            cout << bfs(l) << "\n";
        } else {
            cout << "0" << "\n";
        }
    }
    return 0;
}
