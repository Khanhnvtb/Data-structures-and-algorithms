//
// Created by khanhnvtb on 17/06/2021.
//
/* Ý tưởng:
*/
//khuyến khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int n, pre[1005], in[1005], preIndex;
map <int, int> hm;

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> pre[i];
}

void printPostorder(int start, int end) {
    if (start > end) return; // bắt đầu lớn hơn kết thúc là đã in hết mảng
    int inIndex = hm[pre[preIndex++]]; // tìm chỉ mục gốc của cây hiện tại trong mảng duyệt thứ tự trước
    //tăng preIndex lên 1 vì gốc của cây con đứng ngay sau chỉ mục trước hiện tại
    printPostorder (start, inIndex - 1); //tiếp tục tìm gốc của cây con bên trái
    printPostorder (inIndex + 1, end); // tiếp tục tìm gốc của cây con bên phải
    cout << in[inIndex] << " "; // in ra gốc của cây hiện tại
}

void solve() {
    preIndex = 0; //chỉ mục trước của mảng duyệt thứ tự giữa bắt đầu ở 0 vì trong duyệt thứ tự giữa gốc ở đầu tiên
    for (int i = 0; i < n; i++) hm[in[i]] = i; //đánh dấu vị trí của phần tử trong mảng duyệt thứ tự giữa
    printPostorder (0, n - 1); //tìm gốc của cây con với phạm vi là cả mảng
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