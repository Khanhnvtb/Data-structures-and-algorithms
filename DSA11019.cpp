//
// Created by khanhnvtb on 18/06/2021.
//
/* Ý tưởng: 
*/
//khuyến khích thực hiện thực hành trước khi đi vào giải pháp.

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
    if (preIndex == n)
        return;
    if (pre[preIndex] < minval || pre[preIndex] > maxval) {
        return;
    }
    int val = pre[preIndex];
    preIndex++;
    find (minval, val, preIndex);
    find (val, maxval, preIndex);
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