//
// Created by khanhnvtb on 18/06/2021.
//
/* Ý tưởng: 
*/
//khuyến khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int left, right;
};

int n, in[1005], lv[1005], lvIndex;
map <int, int> hm;
Node node[1005];

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> lv[i];
}

void printPostorder(int res) {
    if (res == -1) return;
    printPostorder (node[res].left);
    printPostorder (node[res].right);
    cout << res << " ";
}

void buildTree() {
    queue <pair <int, pair <int, int> > > q;
    q.push ({lv[0], {0, n - 1}});
    while (!q.empty ()) {
        int tmp = q.front ().first;
        int start = q.front ().second.first;
        int end = q.front ().second.second;
        int inIndex = hm[tmp];
        if (start < inIndex) {
            node[tmp].left = lv[lvIndex];
            lvIndex++;
            q.push ({node[tmp].left, {start, inIndex - 1}});
        }
        if (inIndex < end) {
            node[tmp].right = lv[lvIndex];
            lvIndex++;
            q.push ({node[tmp].right, {inIndex + 1, end}});
        }
        q.pop ();
    }
}

void solve() {
    lvIndex = 1;
    for (int i = 0; i < n; i++) {
        hm[in[i]] = i;
        node[in[i]].left = -1;
        node[in[i]].right = -1;
    }
    buildTree ();
    printPostorder (lv[0]);
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