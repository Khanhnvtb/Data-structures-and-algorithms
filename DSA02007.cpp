//
// Created by khanh on 16/04/2021.
//
/*
Cho số tự nhiên K và xâu ký tự các chữ số S.  Nhiệm vụ của bạn là đưa ra số lớn nhất bằng cách thực hiện nhiều nhất K
lần đổi chỗ các ký tự trong S. Ví dụ K =3 và S = “1234567” ta được “7654321”.
Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số K; dòng tiếp theo là xâu ký tự S.
T, K, S thỏa mãn ràng buộc: 1≤T ≤100; 1≤K≤10; 1≤.lenght(S)≤7.
Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input                          Output
3
4
1234567                        7654321
3
3435335                        5543333
2
1034                           4301
*/
#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string str;
        cin >> str;
        //bắt đầu đổi chỗ từ phần tử đầu
        for (int i = 0 ; i < str.length () ; i++) {
            //khởi tạo giá trị và vị trí lớn nhất hiện tại là phần tử cuối cùng
            int max = str[str.length () - 1], pos = str.length () - 1;
            for (int j = str.length () - 1 ; j > i ; j--) {
                //tìm được giá trị lớn hơn thì cập nhật giá trị và vị trí
                if (str[j] > max) {
                    max = str[j];
                    pos = j;
                }
            }
            //nếu giá trị đó lớn hơn giá trị đang chờ đổi chỗ và k > 0 thì thực hiện đổi chỗ và giảm k
            if (max > str[i] && k > 0) {
                swap (str[i], str[tmp]);
                k--;
            }
        }
        cout << str << "\n";
    }
    return 0;
}

