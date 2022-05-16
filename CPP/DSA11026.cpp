//
// Created by khanhnvtb on 18/06/2021.
//
/* Ý tưởng: 
*/
//khuyến khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int n, a[1005];

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void printPreorder(int start, int end) {
    if (start > end) return;
    int size = end - start + 1;
    int preIndex = start + size / 2;
    if (size % 2 == 0) preIndex--;
    printPreorder (start, preIndex - 1);
    printPreorder (preIndex + 1, end);
    cout << a[preIndex] << " ";
}

void solve() {
    sort (a, a + n);
    printPreorder (0, n - 1);
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