//
// Created by khanh on 15/04/2021.
//
/*
Cho ma trận vuông Ci,j cấp N (1<= i, j <= N<=10) gồm N2 số tự nhiên và số tự nhiên K (các số trong ma trận không nhất
thiết phải khác nhau và đều không quá 100, K không quá 10^4). Hãy viết chương trình lấy mỗi hàng, mỗi cột duy nhất một
phần tử sao cho tổng các phần tử này đúng bằng K.
Dữ liệu vào: Dòng 1 ghi hai số N và K. N dòng tiếp theo ghi ma trận C.
Kết quả: dòng đầu ghi số cách tìm được. Mỗi dòng tiếp theo ghi một cách theo vị trí của số đó trong lần lượt từng hàng
của ma trận. Xem ví dụ để hiểu rõ hơn.

INPUT                               OUTPUT
3 10

2 4 3                               2

1 3 6                               1 3 2

4 2 4                               3 2 1
*/
#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[20][20];
bool used[20]={0};
int b[20];
vector<int>res;
int s=0;
//sinh ra các hoán vị kế tiếp của n
void Try(int pos) {
    for (int i = 1 ; i <= n ; i++) {
        if (used[i] == 0) {
            b[pos] = i;
            used[i] = 1;
            //khi tìm được 1 cấu hình sẽ kiểm tra xem tổng của các vị trí trên ma trận có bằng k không
            if (pos == n) {
                s = 0;
                for (int j = 1 ; j <= n ; j++) {
                    s += a[j][b[j]];
                }
                if (s == k) {
                    for (int j = 1 ; j <= n ; j++) {
                        res.push_back (b[j]);
                    }
                }
            } else {
                Try (pos + 1);
            }
            used[i] = 0;
        }
    }
}
main() {
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cin >> a[i][j];
        }
    }
    Try (1);
    //in ra số cặp
    cout << res.size () / n;
    //in ra kết quả
    for (int i = 0 ; i < res.size () ; i++) {
        if (i % n == 0) {
            cout << endl;
        }
        cout << res[i] << " ";
    }
    return 0;
}