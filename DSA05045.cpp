//
// Created by khanhnvtb on 15/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

struct data{
    int w, c;
};

int n;
double W;
data a[105];

bool cmp(data x, data y) {
    double r1 = (double) x.c / (double) x.w;
    double r2 = (double) y.c / (double) y.w;
    if (r1 > r2) return true;
    return false;
}

void init() {
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        cin >> a[i].c >> a[i].w;
    }
}

void solve() {
    sort (a, a + n, cmp);
    double maxValue = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].w <= W) {
            maxValue += a[i].c;
            W -= a[i].w;
        } else {
            maxValue += a[i].c * (W / a[i].w);
            break;
        }
    }
    cout << setprecision (2) << fixed << maxValue << endl;
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