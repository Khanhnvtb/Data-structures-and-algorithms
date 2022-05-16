//
// Created by KhanhNVTB on 12/04/2021.
//
/*
Một xâu kí tự S = (s1, s2, .., sn) được gọi là xâu AB độ dài n nếu với mọi siÎS thì si hoặc là kí tự A hoặc si là
kí tự B . Ví dụ xâu S = “ABABABAB” là một xâu AB độ dài 8. Cho số tự nhiên N và số tự nhiên K (1£K<N£15 được nhập từ bàn
phím), hãy viết chương trình liệt kê tất cả các xâu AB có độ dài N chứa duy nhất một dãy K kí tự A liên tiếp.
Dữ liệu vào chỉ có một dòng ghi hai số N và K.
Kết quả ghi ra màn hình theo khuôn dạng:
Dòng đầu tiên ghi lại số các xâu AB thỏa mãn yêu cầu bài toán;
Những dòng kế tiếp, mỗi dòng ghi lại một xâu AB thỏa mãn. Các xâu được ghi ra theo thứ tự từ điển.
INPUT                                  OUTPUT
5 3                                    5
                                       AAABA
                                       AAABB
                                       ABAAA
                                       BAAAB
                                       BBAAA
*/
#include<bits/stdc++.h>
using namespace std;
int a[15];
int n, k, res;
vector <int> b;
//khởi tạo cấu hình đầu tiên
void khoitao() {
    for ( int i = 0 ; i < n ; i ++ ) {
        a[i] = 0;
    }
}
void in() {
    //in ra kết quả
    cout << res << "\n";
    for ( int i = 0 ; i < b.size ( ) ; i ++ ) {
        if ( b[i] == 0 ) {
            cout << "A";
        } else {
            cout << "B";
        }
        //nếu in xong 1 cặp thì xuống dòng
        if ( i % n == n - 1 ) {
            cout << "\n";
        }
    }
}
void sinh(int dem, int cnt) {
    //sinh xâu nhị phân kế tiếp
    for ( int i = n - 1 ; i >= 0 ; i -- ) {
        if ( a[i] == 0 ) {
            a[i] = 1;
            for ( int j = i + 1 ; j < n ; j ++ ) {
                a[j] = 0;
            }
            //đếm số cặp có A kí tự A liền nhau
            for ( int j = 0 ; j < n ; j ++ ) {
                if ( a[j] == 0 ) {
                    dem ++;
                } else {
                    if ( dem == k ) {
                        cnt ++;
                    }
                    if ( cnt > 1 ) {
                        break;
                    }
                    dem = 0;
                }
            }
            if ( dem == k ) {
                cnt ++;
            }
            //nếu số cặp đúng bằng 1 thì cập nhật kết quả và chuyển các phần tử vào vector b
            if ( cnt == 1 ) {
                for ( int j = 0 ; j < n ; j ++ ) {
                    b.push_back ( a[j] );
                }
                res ++;
            }
            //gán lại các giá trị để bắt đầu vòng lặp tiếp để tìm các xâu nhị phân tiếp theo
            dem = 0, cnt = 0, i = n;
        }
    }
}
main() {
    cin >> n >> k;
    res = 0;
    khoitao ( );
    sinh ( 0, 0 );
    in ( );
}
