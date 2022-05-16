//
// Created by KhanhNVTB on 26/04/2021.
//
/*Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu này (các phần tử không nhất thiết phải liên tiếp nhau).

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng, mô tả xâu S1 và S2, mỗi xâu có độ dài không quá 1000 và chỉ gồm các chữ cái in hoa.

Output:  Với mỗi test, in ra độ dài dãy con chung dài nhất trên một dòng.

Ví dụ:
Input                             Output
2

AGGTAB                            4

GXTXAYB

AA                                0

BB
*/
#include<bits/stdc++.h>
using namespace std;
main() {
    int t;
    cin >> t;
    while (t--) {
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        int n = str1.length ();
        int m = str2.length ();
        //mảng a lưu trữ độ dài độ dài xâu con chung dài nhất
        int a[n + 1][m + 1];
        //1 trong 2 xâu rỗng thì độ dài xâu con chung dài nhất là 0
        for (int i = 0 ; i <= n ; i++) {
            a[i][0] = 0;
        }
        for (int i = 0 ; i <= m ; i++) {
            a[0][i] = 0;
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                //nếu ký tự cuối cùng của 2 xâu giống nhau thì bằng độ dài xâu con chung trước cộng 1
                if (str1[i - 1] == str2[j - 1]) {
                    a[i][j] = a[i - 1][j - 1] + 1;
                } else {
                    /*
                    nếu ký tự cuối cùng khác nhau thì độ dài xâu con dài nhất sẽ là max của xâu trước đó của xâu 1 và
                    xâu 2 với xâu trước đó của xâu 2 với xâu 1
                     */
                    a[i][j] = max (a[i - 1][j], a[i][j - 1]);
                }
            }
        }
        //in ra kết quả
        cout << a[n][m] << endl;
    }
    return 0;
}