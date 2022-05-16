//
// Created by KhanhNVTB on 12/04/2021.
//
/*
Số nhị phân được xem là cách mặc định biểu diễn các số. Tuy nhiên, trong nhiều ứng dụng của điện tử và truyền thông
lại dùng một biến thể của mã nhị phân đó là mã Gray. Mã Gray độ dài n có mã đầu tiên là n số 0, mã kế tiếp của nó
là một xâu nhị phân độ dài n khác biệt với xâu trước đó một bít. Ví dụ với n=3 ta có 23 mã Gray như sau: 000, 001,
011, 010, 110, 111, 101, 100. Hãy viết chương trình liệt kê các mã Gray có độ dài n.
Input:
Dòng đầu tiên là số lượng test T.
T dòng kế tiếp ghi lại mỗi dòng một test. Mỗi test là một số tự nhiên n.
T, n thỏa mãn ràng buộc: 1≤T, n≤10.
Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input                             Output
2

3                                 000 001 011 010 110 111 101 100

4                                 0000 0001 0011 0010 0110 0111 0101 0100 1100 1101 1111 1110 1010 1011 1001 1000
*/
#include<bits/stdc++.h>
using namespace std;
int n;
main() {
    int t;
    cin >> t;
    while ( t -- ) {
        cin >> n;
        //khởi tạo cấu hình ban đầu
        int a[n] = { 0 };
        //in ra cấu hình ban đầu
        for ( int i = 0 ; i < n ; i ++ ) {
            cout << a[i];
        }
        cout << " ";
        //sinh ra các mã nhị phân
        for ( int i = n - 1 ; i >= 0 ; i -- ) {
            if ( a[i] == 0 ) {
                a[i] = 1;
                for ( int j = i + 1 ; j < n ; j ++ ) {
                    a[j] = 0;
                }
                //chuyển đổi mã nhị phân thành mã gray sau đó in
                cout << a[0];
                for ( int i = 1 ; i < n ; i ++ ) {
                    if ( a[i] + a[i - 1] == 1 ) {
                        cout << "1";
                    } else {
                        cout << "0";
                    }
                }
                cout << " ";
                i = n;
            }
        }
        cout << endl;
    }
    return 0;
}