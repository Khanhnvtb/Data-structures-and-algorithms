//
// Created by khanhnvtb on 17/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

struct data {
    long long val;
    int cntSon;
};

int n, father[200005];
data a[200005];

void init() {
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> father[i];
}

void solve() {
    for (int i = 1; i <= n; i++) {
        a[i].cntSon = 1;
        a[i].val = 0;
    }
    for (int i = n; i >= 1; i--) {
        a[i].val += a[i].cntSon;
        a[father[i]].cntSon += a[i].cntSon;
        a[father[i]].val += a[i].val;
    }
    for (int i = 1; i <= n; i++) cout << a[i].val << " ";
}

int main() {
    init ();
    solve ();
    return 0;
}