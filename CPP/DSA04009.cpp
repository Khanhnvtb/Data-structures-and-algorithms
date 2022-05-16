//
// created by khanh
//
/*
Cho ma trận vuông A kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận X = A^K với K là số nguyên cho trước.
Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 1e9+7.
Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test bắt gồm một số nguyên N và K (1 ≤ N ≤ 10, 1 ≤ K ≤ 1e9) là kích thước của ma trận và số mũ.
Output:

Với mỗi test, in ra kết quả của ma trận X.
Input:                         Output:

2

2 5
1 1                            8 5
1 0                            5 3

3 1000000000
1 2 3                          597240088 35500972 473761863
4 5 6                          781257150 154135232 527013321
7 8 9                          965274212 272769492 580264779
*/
#include<bits/stdc++.h>
using namespace std;
long m=1e9+7;
int n;
long k;
long long a[10][10],repa[10][10];
//viết hàm nhân 2 ma trận
void mul(long long a[][10], long long b[][10]) {
    //khai báo một ma trận trung gian
    long long tmp[10][10] = {0};
    //nhân ma trận a và b
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            for (int k = 0; k < n; k ++) {
                //nhân hàng và cột và thực hiện chia dư cho m
                tmp[i][j] += (a[i][k] % m * b[k][j] % m) % m;
            }
        }
    }
    //gán ma trận a bằng ma trận trung gian vừa tìm
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            a[i][j] = tmp[i][j] % m;
        }
    }
}
//viết hàm tính luỹ thừa
void power(long long a[][10], long k) {
    //nếu k=1 thì a không thay đổi
    if (k == 1) return;
    //nếu k>1 tính luỹ thừa của a và k/2
    power(a, k / 2);
    //nhân 2 luỹ thừa của a và k/s với nhau
    mul(a, a);
    /*
    nếu k%2=0 thì a^n=a^(n/2)*a^(n/2)
    nếu k%2=1 thì a^n=a^(n/2)*a^(n/2)*a
    */
    if (k % 2 == 1) {
        mul(a, repa);
    }
}
main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n >> k;
        //nhập vào ma trận a và tạo 1 nhân bản của nó
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                cin >> a[i][j];
                repa[i][j] = a[i][j];
            }
        }
        //gọi hàm tính luỹ thừa của ma trận a
        power(a, k);
        //in ra kết quả
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}


