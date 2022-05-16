//
//creatd by KhanhNVTB on 15/04/2021
/*
Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. Một con chuột đi từ ô đầu tiên góc
trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:
Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
Left (L): Chuột được phép sang trái dưới nếu ô bên trái nó có giá trị 1.
Up (U): Chuột được phép lên trên nếu ô trên nó có giá trị 1.
Hãy đưa ra tất cả các hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.
Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là kích cỡ của mê cung;
dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤8; 0≤A[i][j] ≤1.
Output:
Đưa ra các xâu ký tự được sắp xếp, trong đó mỗi xâu là một đường đi của con chuột trong mê cung. In ra đáp án theo thứ
tự từ điển. Đưa ra -1 nếu chuột không đi được đến đích.
Input                                   Output
3
4
1 0 0 0                                 DRDDRR

1 1 0 1

0 1 0 0

0 1 1 1
4
1 0 0 0                                 DDRDRR DRDDRR

1 1 0 1

1 1 0 0

0 1 1 1

5

1 0 0 0 0                               DDRRURRDDD DDRURRRDDD DRDRURRDDD DRRRRDDD

1 1 1 1 1

1 1 1 0 1

0 0 0 0 1

0 0 0 0 1
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100][100];
int used[100][100];
vector <string> res;
void Try(int i, int j,string str) {
    //nếu đã đến đích thì thêm đường đi vào kết quả
    if (i == n - 1 && j == n - 1) {
        res.push_back (str);
        return;
    }
    //nếu bên dưới có lối đi và chưa đi qua thì đi xuống và thêm D vào chuỗi lối đi
    if (i < n - 1 && a[i + 1][j] == 1 && used[i + 1][j] == 0) {
        used[i][j] = 1;
        Try (i + 1, j, str + "D");
        //trả lại khi chưa đi qua
        used[i][j] = 0;
    }
    //nếu bên phải có lối đi và chưa đi qua thì đi xuống và thêm R vào chuỗi lối đi
    if (j < n - 1 && a[i][j + 1] == 1 && used[i][j + 1] == 0) {
        used[i][j] = 1;
        Try (i, j + 1, str + "R");
        //trả lại khi chưa đi qua
        used[i][j] = 0;
    }
    //nếu bên trái có lối đi và chưa đi qua thì đi xuống và thêm L vào chuỗi lối đi
    if (j > 0 && a[i][j - 1] == 1 && used[i][j - 1] == 0) {
        used[i][j] = 1;
        Try (i, j - 1, str + "L");
        //trả lại khi chưa đi qua
        used[i][j] = 0;
    }
    //nếu bên trên có lối đi và chưa đi qua thì đi xuống và thêm U vào chuỗi lối đi
    if (i > 0 && a[i - 1][j] == 1 && used[i - 1][j] == 0) {
        used[i][j] = 1;
        Try (i - 1, j, str + "U");
        //trả lại khi chưa đi qua
        used[i][j] = 0;
    }
}
main() {
    int t;
    cin >> t;
    while (t--) {
        //làm trống vector kết quả
        res.clear ();
        cin >> n;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                cin >> a[i][j];
                used[i][j] = 0;
            }
        }
        if (a[0][0] == 0 || a[n - 1][n - 1] == 0) {
            cout << -1;
        } else {
            Try (0, 0, "");
            if (res.size () == 0) {
                cout << -1;
            } else {
                sort (res.begin (), res.end ());
                for (int i = 0 ; i < res.size () ; i++) {
                    cout << res[i] << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}

