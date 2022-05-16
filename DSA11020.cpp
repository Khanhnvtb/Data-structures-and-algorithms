//
// Created by khanhnvtb on 18/06/2021.
//
/* Ý tưởng: 
*/
//khuyến khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int n, in[1005];

void init(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>in[i];
}

int isBST() {
    if (n == 1) return 1;
    for (int i = 1; i < n; i++) {
        if (in[i - 1] >= in[i]) return 0;
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        cout << isBST() << endl;
    }
    return 0;
}