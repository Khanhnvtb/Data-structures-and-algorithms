#include <bits/stdc++.h>
using namespace std;
int n, k, res, start_row, start_col, dest_row, dest_col, vs[9][9];
void init(){
    string str;
    getline(cin, str);

    start_col = str[0] - 96;
    start_row = str[1] - 48;
    dest_col = str[3] - 96;
    dest_row = str[4] - 48;
}
int bfs() {
    queue <pair <int, int> > q;
    q.push({start_row, start_col});
    memset(vs, 0, sizeof(vs));
    vs[start_row][start_col] = 1;
    while (! q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i > 2 && j > 1 && vs[i - 2][j - 1] == 0) {
            vs[i - 2][j - 1] = vs[i][j] + 1;
            q.push({i - 2, j - 1});
        }
        if (i > 2 && j < 8 && vs[i - 2][j + 1] == 0) {
            vs[i - 2][j + 1] = vs[i][j] + 1;
            q.push({i - 2, j + 1});
        }
        if (i > 1 && j > 2 && vs[i - 1][j - 2] == 0) {
            vs[i - 1][j - 2] = vs[i][j] + 1;
            q.push({i - 1, j - 2});
        }
        if (i > 1 && j < 7 && vs[i - 1][j + 2] == 0) {
            vs[i - 1][j + 2] = vs[i][j] + 1;
            q.push({i - 1, j + 2});
        }
        if (i < 8 && j > 2 && vs[i + 1][j - 2] == 0) {
            vs[i + 1][j - 2] = vs[i][j] + 1;
            q.push({i + 1, j - 2});
        }
        if (i < 8 && j < 7 && vs[i + 1][j + 2] == 0) {
            vs[i + 1][j + 2] = vs[i][j] + 1;
            q.push({i + 1, j + 2});
        }
        if (i < 7 && j > 1 && vs[i + 2][j - 1] == 0) {
            vs[i + 2][j - 1] = vs[i][j] + 1;
            q.push({i + 2, j - 1});
        }
        if (i < 7 && j < 8 && vs[i + 2][j + 1] == 0) {
            vs[i + 2][j + 1] = vs[i][j] + 1;
            q.push({i + 2, j + 1});
        }
        if (vs[dest_row][dest_col] != 0) {
            return vs[dest_row][dest_col] - 1;
        }
    }
}
void solve() {
    cout << bfs() << endl;
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
