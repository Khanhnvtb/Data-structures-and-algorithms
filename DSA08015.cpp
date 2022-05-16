//
// Created by khanhnvtb on 06/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.
#include <bits/stdc++.h>
using namespace std;
int a, b, c, vs[30][30][30];
char d[30][30][30];
int row[] = {-1, 0, 0, 1};
int col[] = {0, -1, 1, 0};
bool check(int x, int y) {
    if (x < 0 || y < 0 || x >= b || y >= c) return false;
    return true;
}
struct item {
    int fi, se, th;
};
item s,e;
void init() {
    cin >> a >> b >> c;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                cin >> d[i][j][k];
                if (d[i][j][k] == 'S') {
                    s = {i, j, k};
                }
                if (d[i][j][k] == 'E') {
                    e = {i, j, k};
                }
            }
        }
    }
}
int bfs() {
    queue <item> q;
    q.push ({s.fi, s.se, s.th});
    vs[s.fi][s.se][s.th] = 1;
    while (!q.empty ()) {
        item tmp = q.front ();
        q.pop ();
        if (tmp.fi > 0 && d[tmp.fi - 1][tmp.se][tmp.th] != '#' && vs[tmp.fi - 1][tmp.se][tmp.th] == 0) {
            vs[tmp.fi - 1][tmp.se][tmp.th] = vs[tmp.fi][tmp.se][tmp.th] + 1;
            q.push ({tmp.fi - 1, tmp.se, tmp.th});
        }
        if (d[tmp.fi + 1][tmp.se][tmp.th] != '#' && tmp.fi + 1 < a && vs[tmp.fi + 1][tmp.se][tmp.th] == 0) {
            vs[tmp.fi + 1][tmp.se][tmp.th] = vs[tmp.fi][tmp.se][tmp.th] + 1;
            q.push ({tmp.fi + 1, tmp.se, tmp.th});
        }
        for (int i = 0; i < 4; i++) {
            int x = tmp.se + row[i];
            int y = tmp.th + col[i];
            if (check (x, y) && d[tmp.fi][x][y] != '#' && vs[tmp.fi][x][y] == 0) {
                vs[tmp.fi][x][y] = vs[tmp.fi][tmp.se][tmp.th] + 1;
                q.push ({tmp.fi, x, y});
            }
        }
        if (vs[e.fi][e.se][e.th] != 0) {
            return vs[e.fi][e.se][e.th] - 1;
        }
    }
    return -1;
}
void solve() {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                vs[i][j][k] = 0;
            }
        }
    }
    cout << bfs () << endl;
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
