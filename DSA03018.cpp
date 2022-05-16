//
// Created by khanh on 08/04/2021
//
/*SỐ MAY MẮN
Hoàng yêu thích các số may mắn. Ta biết rằng một số là số may mắnnếu biểu diễn thập phân của nó chỉ chứa các
chữ số may mắn là 4 và 7. Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải.  Hoàng muốn tìm số
may mắn bé nhất có tổng các chữ số bằng n. Hãy giúp anh ấy.
Dữ liệu vào: Dòng đầu ghi số bộ test, mỗi bộ test có một dòng chứa số nguyên n (1 ≤ n ≤ 10^6)
— tổng các chữ số của số may mắn cần tìm.
Kết quả: In ra trên 1 dòng số may mắn bé nhất, mà tổng các chữ số bằng n.
Nếu không tồn tại số thỏa mãn, in ra -1.
Input           Output
2

11              47

10              -1
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    // nhập vào số bộ test t
    int t;
    cin>>t;
    while(t--) {
        //nhập vào số nguyên n là tổng các chữ số của số may mắn
        long n;
        cin >> n;
        // khởi tạo số chữ số 7 tối đa
        long r = n / 7;
        // khởi tạo số chữ số 4 là 0
        long l = 0;
        // sum là tổng các chữ số hiện tại
        long sum = r * 7;
        // vòng lặp luôn đúng
        while (1) {
            /* khi tổng bằng n thì dừng vòng lặp, nếu nhỏ hơn n thì tăng thêm 1 chữ số 4, nếu lớn hơn n thì giảm 1
            chữ số 7*/
            if (sum == n) {
                break;
            } else if (sum < n) {
                sum += 4;
                l++;
            } else {
                sum -= 7;
                r--;
            }
            //khi số chữ số 7 còn 0 hoặc số chứ số 4 tối đa thì dừng vòng lặp
            if (r == 0 || l == n / 4) {
                break;
            }
        }
        // nếu tổng bằng n thì in ra số tìm được , không thì in ra -1
        if (sum == n) {
            //liệt kê các chữ số 4 ở trước
            for (int i = 0; i < l; i++) {
                cout << "4";
            }
            // liệt kê các chữ số 7 ở sau
            for (int i = 0; i < r; i++) {
                cout << "7";
            }
        } else {
            cout << "-1";
        }
        cout << endl;
    }
}
