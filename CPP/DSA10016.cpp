//
// Created by khanhnvtb on 17/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

int n, parent[105], Rank[105];
Point p[105];
vector <pair <double, pair <int, int> > >edge;

void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
}

double dist(Point a, Point b) {
    return sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int find(int i) {
    if (i != parent[i]) parent[i] = find (parent[i]);
    return parent[i];
}

void Union(int x, int y) {
    if (Rank[x] > Rank[y]) parent[y] = x;
    else parent[x] = y;
    if (Rank[x] == Rank[y]) Rank[y]++;
}

void solve() {
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edge.push_back ({dist (p[i], p[j]), {i, j}});
        }
    }
    sort (edge.begin (), edge.end ());
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        Rank[i] = 0;
    }
    double res = 0;
    for (int i = 0; i < edge.size (); i++) {
        int x = find (edge[i].second.first);
        int y = find (edge[i].second.second);
        if (x != y) {
            res += edge[i].first;
            Union (x, y);
        }
    }
    cout << setprecision (6) << fixed << res << endl;
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