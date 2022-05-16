//
// Created by KhanhNVTB on 13/04/2021.
//
/*
Cho số nguyên dương N. Mỗi bước, bạn sẽ biến đổi N thành [N/2], N mod 2, [N/2]. Sau khi thực hiện một cách triệt
để, ta thu được một dãy số chỉ toàn số 0 và 1.
Nhiệm vụ của bạn là hãy đếm các số bằng 1 trong đoạn [L, R] của dãy số cuối cùng.
Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 3 số nguyên N, L, R (1 ≤ N, L, R < 250, 0 ≤ R-L ≤ 100 000).
Output:
Với mỗi test, in ra đáp án trên một dòng.

Input                                    Output
2

7 2 5                                    4

10 3 10                                  5
*/
#include<bits/stdc++.h>
using namespace std;
//vector a dùng để lưu các vị trí chính giữa của dãy con
vector <long long> a;
//hàm find dùng để tìm kiếm phần tử tại vị trí i
long long find(long long k,long long n,long long x) {
    /*
    nếu k nhỏ hơn phần tử chính giữa hiện tại thì tìm kiếm với n/2 và giảm phần tử chính giữa xuống 2 lần, nếu k đúng
    bằng phần tử chính giữa thì trả về kết quả là phép dư của n cho 2, còn lại sẽ tìm kiếm với n/2 và phần tử dối xứng
    với k qua phần tử chính giữa hiện tại
    */
    if (k < a[x]) {
        return find (k, n / 2, x - 1);
    } else if (k == a[x]) {
        return n % 2;
    } else {
        return find (2 * a[x] - k, n / 2, x - 1);
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, l, r, cnt = 0;
        cin >> n >> l >> r;
        //xoá sạch vector a
        a.clear ();
        //tìm số mũ lớn nhất của 2^i
        long long tmp = log2 (n);
        //đưa các luỹ thừa của 2 vào vector
        for (long long i = 1 ; i <= tmp ; i++) {
            a.push_back (pow (2, i));
        }
        //tìm kiếm từ l đến r nếu i lẻ thì tại đó là phần tử 1 còn chẵn thì gọi hàm tìm kiếm
        for (long long i = l ; i <= r ; i++) {
            if (i % 2 == 1) {
                cnt++;
            } else {
                cnt += find (i, n, tmp - 1);
            }
        }
        //in ra kết quả
        cout << cnt << "\n";
    }
    return 0;
}

