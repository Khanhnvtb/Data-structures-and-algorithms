//
// Created by khanh on 16/04/2021.
//
*/
Cho tập từ ghi trong trừ điển dic[] và một bảng hai chiều A[M][N] các ký tự. Hãy tạo nên tất cả các từ có mặt trong từ
        điển dic[] bằng cách nối các ký tự kề nhau trong mảng A[][]. Chú ý, phép nối các ký tự kề nhau trong mảng A[][] được
        thực hiện theo 8 hướng nhưng không có phần tử A[i][j] nào được lặp lại. Ví dụ với từ điển dic[] ={ “GEEKS”, “FOR”,
“QIUZ”, “GO”} và mảng A[][] dưới đây sẽ cho ta kết quả: “GEEKS”, “QUIZ”
G I Z

        U E K

Q S E
        Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào ba số K, M, N tương ứng với số
từ của từ điển dic[], số hàng và số cột của ma trận ký tự A[M][N]; dòng tiếp theo đưa vào K từ của từ điển dic[]; dòng
        cuối cùng đưa vào các phần tử A[i][j].
T, K, M, N thỏa mãn ràng buộc: 1≤T ≤10; 1≤K≤100; 1≤ M, N ≤3.
Output:
Đưa ra theo thứ tự tăng dần các từ có mặt trong từ điển dic[] được tạo ra từ ma trận A[][]. Đưa ra -1 nếu không thể tạo
ra từ nào thuộc dic[] từ A[][].

Input                                Output
1
4  3  3
GEEKS FOR QUIZ GO                    GEEKS QUIZ
G I Z

        U E K

Q S E
*/
#include <bits/stdc++.h>
using namespace std;
int k, m, n;
string str[110];
char a[5][5];
//mảng used dùng để đánh dấu phần tử đã sử dụng
int used[5][5];
vector <string> res;
//mảng hàng dùng để lưu toạ độ của hàng theo 8 hướng so với vị trí hiện tại
int hang[]={-1, -1, -1, 0, 0, 1, 1, 1};
//mảng cột dùng để lưu toạ độ của cột theo 8 hướng so với vị trí hiện tại
int cot[]={-1, 0, 1, -1, 1, -1, 0, 1};
void Try(int i,int j, string tmp) {
    //nếu có thể tìm ra từ thì lưu từ đó vào kết quả
    for (int l = 0 ; l < k ; l++) {
        if (str[l] == tmp) {
            res.push_back (tmp);
        }
    }
    //thử với 8 hướng của vị trí hiện tại
    for (int l = 0 ; l < 8 ; l++) {
        int x = i + hang[l];
        int y = j + cot[l];
        //nếu hướng đó chưa được sử dụng thì đi đến vị trí đó
        if (x > 0 && y > 0 && x <= m && y <= n && used[x][y] == 0) {
            //đánh dấu là đã sử dụng
            used[x][y] = 1;
            //tiếp tục thử tại vị trí hiện tại
            Try (x, y, tmp + a[x][y]);
            //sử dụng xong gán lại vị trí chưa sử dụng để đi hướng khác
            used[x][y] = 0;
        }
    }
}
main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> k >> m >> n;
        for (int i = 0 ; i < k ; i++) {
            cin >> str[i];
        }
        for (int i = 1 ; i <= m ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                cin >> a[i][j];
            }
        }
        res.clear ();
        for (int i = 1 ; i <= m ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                //đánh dấu tất cả đều chưa sử dụng
                memset (used, 0, sizeof (used));
                //gán vị trí hiện tại đã sử dụng
                used[i][j] = 1;
                string s = "";
                //thử tại vị trí hiện tại
                Try (i, j, s + a[i][j]);
            }
        }
        //in ra kết quả
        if (res.size () == 0) {
            cout << "-1";
        } else {
            for (int i = 0 ; i < res.size () ; i++) {
                cout << res[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
