//
// Created by khanhnvtb on 17/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int v, e, cnt, Rank[105], parent[105];
vector <pair <int, pair<int, int> > >edge;
long long res;

int find(int i) {
    if (i != parent[i]) parent[i] = find (parent[i]);
    return parent[i];
}

void Union(int x, int y) {
    if (Rank[x] > Rank[y]) parent[y] = x;
    else parent[x] = y;
    if (Rank[x] == Rank[y]) Rank[y]++;
}

void init() {
    cin >> v >> e;
    int i, j, k;
    while (e--) {
        cin >> i >> j >> k;
        edge.push_back ({k, {min (i, j), max (i, j)}});
    }
}

void solve() {
    sort (edge.begin (), edge.end ());
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
        Rank[i] = 0;
    }
    res = 0;
    for (int i = 0; i < edge.size (); i++) {
        int x = find (edge[i].second.first);
        int y = find (edge[i].second.second);
        if (x != y) {
            res += edge[i].first;
            Union (x, y);
        }
    }
    cout << res << endl;
    edge.clear ();
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