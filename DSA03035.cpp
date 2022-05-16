//
// Created by khanhnvtb on 16/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void solve() {
    int maxIncre = 1;
    int cnt[n+1]={0};
    for (int i = 0; i < n; i++) {
        if (cnt[a[i] - 1] == 0) cnt[a[i]] = 1;
        else cnt[a[i]] = cnt[a[i] - 1] + 1];
        maxIncre = max (maxIncre, cnt[a[i]]);
    }
    cout << n - maxIncre ;
}

int main() {
    init ();
    solve ();
    return 0;
}