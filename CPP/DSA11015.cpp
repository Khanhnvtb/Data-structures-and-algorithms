//
// Created by khanhnvtb on 17/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

void makeNode(Node *node, int b, char c) {
    if (c == 'L') node->left = new Node (b);
    else node->right = new Node (b);
}

void findNode(Node *node, int a, int b, char c) {
    if (!node) return;
    if (node->data == a) makeNode (node, b, c);
    else {
        findNode (node->left, a, b, c);
        findNode (node->right, a, b, c);
    }
}

long long maxPath(Node *node, long long &res) {
    if (!node) return 0;
    if (!node->left && !node->right) return node->data;
    long long ls = maxPath (node->left, res);
    long long rs = maxPath (node->right, res);
    if (node->left && node->right) {
        res = max (ls + rs + node->data, res);
        return max (ls, rs) + node->data;
    }
    if (!node->left) return rs + node->data;
    return ls + node->data;
}

long long maxPathSum(Node *node) {
    long long res = LONG_LONG_MIN;
    long long val = maxPath (node, res);
    if (res == LONG_LONG_MIN) return val;
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        char c;
        cin >> n;
        Node *node = NULL;
        while (n--) {
            cin >> a >> b >> c;
            if (!node) {
                node = new Node (a);
                makeNode (node, b, c);
            } else findNode (node, a, b, c);
        }
        cout << maxPathSum (node) << endl;
    }
    return 0;
}