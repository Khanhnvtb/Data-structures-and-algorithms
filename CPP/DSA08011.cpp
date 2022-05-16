//
// Created by khanh on 01-Jun-21.
//

#include <bits/stdc++.h>
using namespace std;
int n;
string start, target;
set <string> s;
set <int> ::iterator it;
void init() {
    cin >> n;
    s.clear();
    cin.ignore();
    cin >> start >> target;
    for (int i = 0; i < n; i ++) {
        cin.ignore();
        string str;
        cin >> str;
        s.insert(str);
    }
}
int bfs() {
    if (start == target)
        return 0;
    map <string, vector <string>> umap;
    for (int i = 0; i < start.size(); i ++) {
        string str = start.substr(0, i) + "*" + start.substr(i + 1);
        umap[str].push_back(start);
    }
    for (auto it = s.begin(); it != s.end(); it ++) {
        string word = *it;
        for (int j = 0; j < word.size(); j ++) {
            string str = word.substr(0, j) + "*" + word.substr(j + 1);
            umap[str].push_back(word);
        }
    }
    queue <pair <string, int>> q;
    map <string, int> vs;
    q.push({start, 1});
    vs[start] = 1;
    while (! q.empty()) {
        pair <string, int> p = q.front();
        q.pop();
        string word = p.first;
        int dist = p.second;
        if (word == target) {
            return dist;
        }
        for (int i = 0; i < word.size(); i ++) {
            string str = word.substr(0, i) + "*" + word.substr(i + 1);
            vector <string> vect = umap[str];
            for (int j = 0; j < vect.size(); j ++) {
                if (vs[vect[j]] == 0) {
                    vs[vect[j]] = 1;
                    q.push({vect[j], dist + 1});
                }
            }
        }
    }
    return 0;
}
void solve() {
    cout << bfs() << endl;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        init();
        solve();
    }
    return 0;
}