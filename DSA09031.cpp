//
// Created by khanhnvtb on 14/06/2021.
//
/* Ý tưởng: số cặp cừu bằng số con cừu trong 1 thành phần liên thông nhân với số con cừu còn lại chưa được duyệt qua
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

struct data {
    int up, left, right, down;
};

int n, k, m, res, vs[105][105];
data a[105][105]; // mảng lưu trữ vị trí hàng rào
int dx[] = {-1, 0, 0, 1}; // toạ độ x ứng với lên, trái, phải, xuống
int dy[] = {0, -1, 1, 0}; // toạ độ y ứng với lên, trái, phải, xuống
vector <pair <int, int> > b;

bool check(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > n) return false;
    return true;
}

void init() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vs[i][j] = 0;
            a[i][j] = {0, 1, 2, 3}; // đánh dấu tất cả vị trí đều đi được lên, trái, phải, xuống
        }
    }
    int u, v, x, y;
    while (m--) {
        cin >> u >> v >> x >> y;
        if (u == x + 1) {
            a[u][v].up = -1; //đánh dấu có hàng rào
            a[x][y].down = -1; //đánh dấu có hàng rào
        } else if (v == y + 1) {
            a[u][v].left = -1; //đánh dấu có hàng rào
            a[x][y].right = -1; //đánh dấu có hàng rào
        } else if (v == y - 1) {
            a[u][v].right = -1; //đánh dấu có hàng rào
            a[x][y].left = -1; //đánh dấu có hàng rào
        } else {
            a[u][v].down = -1; //đánh dấu có hàng rào
            a[x][y].up = -1; //đánh dấu có hàng rào
        }
    }
    int i, j;
    for (int t = 0; t < k; t++) {
        cin >> i >> j;
        vs[i][j] = 2; //đánh dấu 2 là có cừu, đánh dấu 1 là đã duyệt qua, đánh dấu 0 là không có cừu và chưa duyệt qua
        b.push_back ({i, j});
    }
}

void solve() {
    res = 0;
    int row, col;
    for (int i = 0; i < b.size (); i++) {
        row = b[i].first;
        col = b[i].second;
        if (vs[row][col] == 2) {
            vs[row][col] = 1;
            queue <pair <int, int> > q;
            q.push ({row, col});
            int cnt = 1;
            while (!q.empty ()) {
                row = q.front ().first;
                col = q.front ().second;
                q.pop ();
                if (a[row][col].up == 0) { // nếu bên trên không có hàng rào
                    int x = row + dx[0];
                    int y = col + dy[0];
                    if (check (x, y) && vs[x][y] != 1) { //kiểm tra nếu chưa được duyệt
                        if (vs[x][y] == 2) { //nếu tại vị trí có cừu
                            cnt++; //tăng số con cừu trong 1 thành phần liên thông
                        }
                        vs[x][y] = 1; // đánh dấu đã duyệt qua
                        q.push ({x, y});
                    }
                }
                if (a[row][col].left == 1) { // nếu bên trái không có hàng rào
                    int x = row + dx[1];
                    int y = col + dy[1];
                    if (check (x, y) && vs[x][y] != 1) { //kiểm tra nếu chưa được duyệt
                        if (vs[x][y] == 2) { //nếu tại vị trí có cừu
                            cnt++;
                        }
                        vs[x][y] = 1; //đánh dấu đã duyệt qua
                        q.push ({x, y});
                    }
                }
                if (a[row][col].right == 2) { // nếu bên phải không có hàng rào
                    int x = row + dx[2];
                    int y = col + dy[2];
                    if (check (x, y) && vs[x][y] != 1) { //kiểm tra nếu chưa được duyệt
                        if (vs[x][y] == 2) { //nếu tại vị trí có cừu
                            cnt++;
                        }
                        vs[x][y] = 1; //đánh dấu đã duyệt qua
                        q.push ({x, y});
                    }
                }
                if (a[row][col].down == 3) { // nếu bên dưới không có hàng rào
                    int x = row + dx[3];
                    int y = col + dy[3];
                    if (check (x, y) && vs[x][y] != 1) { //kiểm tra nếu chưa được duyệt
                        if (vs[x][y] == 2) { //nếu tại vị trí có cừu
                            cnt++;
                        }
                        vs[x][y] = 1; //đánh dấu đã duyệt qua
                        q.push ({x, y});
                    }
                }
            }
            k -= cnt; // số con cừu còn lại chưa được duyệt qua
            res += k * cnt; //số cừu trong đàn hiện tại nhân với số con cừu chưa được duyệt qua
        }
    }
    cout << res << endl;
}

int main() {
    init ();
    solve ();
    return 0;
}