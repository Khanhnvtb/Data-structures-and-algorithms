//
// Created by khanhnvtb on 09/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;
long n, res, a[1000005];
void init() {
    cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> a[i];
    }
}
long merge(long l, long m, long r) {
    long i = l, j = m, k = l, cnt = 0;
    long tmp[n];
    while (i < m && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            cnt += m - i;
            tmp[k++] = a[j++];
        }
    }
    while (i < m) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    for (i = l; i <= r; i++) {
        a[i] = tmp[i];
    }
    return cnt;
}
long mergeSort(long l, long r) {
    long cnt = 0;
    if (l < r) {
        long m = l + (r - l) / 2;
        cnt += mergeSort (l, m);
        cnt += mergeSort (m + 1, r);
        cnt += merge (l, m + 1, r);
    }
    return cnt;
}
void solve() {
    res = mergeSort (0, n - 1);
    cout << res << endl;
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