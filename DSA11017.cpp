//
// Created by khanhnvtb on 08/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;
int n;
int pre[1005];
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
}
void find(int minval, int maxval, int& preIndex) {
    if (preIndex == n) //trả về vì không còn phần tử nào nữa
        return;
    if (pre[preIndex] < minval || pre[preIndex] > maxval) {
        //nếu phần tử của mảng không nằm trong phạm vi chỉ định thì nó không thuộc cây con hiện tại
        return;
    }
    //lưu trữ giá trị hiện tại
    int val = pre[preIndex];
    //tìm đến phần tử tiếp theo của mảng
    preIndex++;
    //tìm tất cả phần tử có giá trị giữa min val và val
    find (minval, val, preIndex);
    //tìm tất cả phần tử có giá trị giữa val và maxval
    find (val, maxval, preIndex);
    //in ra kết quả
    cout << val << " ";
}
void solve() {
    int preIndex = 0;
    find (INT_MIN, INT_MAX, preIndex);
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}
