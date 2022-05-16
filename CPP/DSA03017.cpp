//
// Created by KhanhNVTB on 13/04/2021.
//
/*
Cho xâu ký tự S. Ta gọi giá trị của xâu S là tổng bình phương số lần xuất hiện mỗi ký tự trong S. Hãy tìm giá
trị nhỏ nhất của xâu S sau khi thực hiện K lần loại bỏ ký tự.
Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là số K; phần thứ hai là một xâu
ký tự S được viết trên một dòng.
T, S, K thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000; 1≤K≤1000.
Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input                          Output
2

2

ABCCBC                         6
2

AAAB                           2
*/
#include<bits/stdc++.h>
using namespace std;
int k;
main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> k;
        string str;
        cin >> str;
        //sắp xếp lại xâu để đếm số lần xuất hiện
        sort (str.begin (), str.end ());
        //vector a lưu số lần xuất hiện
        vector <int> a;
        a.push_back (0);
        a.push_back (1);
        //vector b lưu số phần tử có cùng số lần xuất hiện
        vector <int> b;
        b.push_back (0);
        //đếm số lần xuất hiện
        for (int i = 1 ; i < str.length () ; i++) {
            if (str[i] == str[i - 1]) {
                a[a.size () - 1]++;
            } else {
                a.push_back (1);
            }
        }
        //sắp xếp tăng dấn số lần xuất hiện
        sort (a.begin (), a.end ());
        //chuyển vector a ứng với số lần xuất hiện và vector b ứng với số phần tử có cùng số lần xuất hiện
        b.push_back (1);
        for (int i = 2 ; i < a.size () ; i++) {
            //nếu bằng số đứng trước thì tăng số lần xuấn hiện ở vector b lên 1 và xoá phần tử đó của vector a
            if (a[i] == a[i - 1]) {
                b[b.size () - 1]++;
                a.erase (a.begin () + i);
                i--;
            } else {
                //nếu gặp phần tử khác thì đánh dấu nó xuất hiện 1 lần
                b.push_back (1);
            }
        }
        //nếu k lớn hơn 0 thực hiện xoá
        while (k > 0) {
            /*
            nếu tích của hiệu số lần xuất hiện lớn nhất và số lần xuất hiện lớn thứ 2 với số phần tử có số lần
            xuất hiện lớn nhất nhỏ hơn hoặc bằng k thì xoá hết để số lần xuất hiện lớn nhất và lớn thứ 2 bằng
            nhau. Khi đó số lần xuất hiện lớn thứ 2 sẽ là lớn nhất và tổng số phần tử cũng tăng 1 khoảng bằng
            số phần tử của số lần xuất hiện lớn nhất trước đó. Xoá phần tử ở cuối của 2 vector và giảm k để tiếp
            tục vòng lặp
            */
            if ((a[a.size () - 1] - a[a.size () - 2]) * b[b.size () - 1] <= k) {
                //giảm k
                k -= (a[a.size () - 1] - a[a.size () - 2]) * b[b.size () - 1];
                //cập nhật số phần tử lớn nhất
                b[b.size () - 2] += b[b.size () - 1];
                //xoá đi 2 phần tử ở cuối vector
                a.pop_back ();
                b.pop_back ();
            } else {
             /*
             nếu tích của hiệu số lần xuất hiện lớn nhất và số lần xuất hiện lớn thứ 2 với số phần tử có số lần
             xuất hiện lớn nhất lớn hơn k thì trừ số lần xuất hiện lớn nhất đi 1 khoảng bằng với chia nguyên của k
             cho số phần tử có số lần xuất hiện lớn nhất. Khi đó k sẽ còn là phần dư của k cho số phần tử có số
             lần xuất hiện lớn nhất. Tiếp tục trừ đi số phần tử đúng bằng giá trị chia dư đó 1 đơn vị. Khi đó có
             2 trường hợp xảy ra là giá trị sau khi trừ đúng bằng số lần xuất hiện nhiều thứ 2 thì ta tăng số phần tử
             có số lần xuất hiện nhiều thứ 2 lên sau đó cập nhật số phần tử xuất hiện nhiều nhất. Trường hợp còn lại
             thì ta cập nhật số phần tử xuất hiện lớn nhất và thêm vào vector a số lần xuất hiện nhiều thứ 2 bằng số
             lần xuất hiện nhiều nhất trừ đi 1 và với số phần tử tương ứng ở vector b là số phần dư bên trên
             */
             // giảm số lần xuất hiện lớn nhất
                a[a.size () - 1] -= k / b[b.size () - 1];
                //trường hợp đầu
                if (a[a.size () - 1] - 1 == a[a.size () - 2]) {
                    //tăng số phần tử xuất hiện nhiều thứ 2
                    b[b.size () - 2] += k % b[b.size () - 1];
                    //cập nhật lại số phần tử xuất hiện nhiều nhất
                    b[b.size () - 1] -= k % b[b.size () - 1];
                } else {
                    //trường hợp 2
                    //thêm vào số lần xuất hiện nhiều thứ 2
                    a.push_back (a[a.size () - 1] - 1);
                    //thêm vào số lần xuất hiện của số phần tử xuất hiện nhiều thứ 2
                    b.push_back (k % b[b.size () - 1]);
                    //cập nhật lại số phần tử có số lần xuất hiện nhiều nhất
                    b[b.size () - 2] -= k % b[b.size () - 2];
                }
                //gán k =0 để kết thúc vòng lặp
                k = 0;
            }
        }
        //khai báo kết quả
        long long res = 0;
        //cập nhật kết quả
        for (int i = 0 ; i < a.size () ; i++) {
            res += b[i] * pow (a[i], 2);
        }
        //in ra kết quả
        cout << res << "\n";
    }
    return 0;
}
