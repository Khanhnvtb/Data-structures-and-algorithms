//
// Created by khanhnvtb on 16/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string str, tmp;
    cin >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'X') str[i] = '1';
        else if (str[i] == 'T') str[i] = '2';
        else str[i] = '3';
    }
    tmp = str;
    sort (str.begin (), str.end ());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == tmp[i]) {
            cnt++;
            tmp[i] = 0;
        }
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = n; j > i; j--) {
            if (tmp[j] == str[i] && tmp[i] == str[j]) {
                res++;
                tmp[i] = 0;
                tmp[j] = 0;
                cnt += 2;
            }
            if (cnt == n) break;
        }
    }
    n -= cnt;
    cout << res + (n / 3) * 2 << endl;
}

int main() {
    solve ();
    return 0;
}