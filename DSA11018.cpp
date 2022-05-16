//
// Created by khanhnvtb on 19/06/2021.
//
/* Ý tưởng: 
*/
//khuyến khích thực hiện thực hành trước khi đi vào giải pháp.

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

int n, lv[1005];

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> lv[i];
}

void printPreOrder(Node *node) {
    if (!node) return;
    cout << node->data << " ";
    printPreOrder (node->left);
    printPreOrder (node->right);
}

Node *levelOrder(Node *node, int data) {
    if (!node) {
        node = new Node (data);
        return node;
    }
    if (data <= node->data) node->left = levelOrder (node->left, data);
    else node->right = levelOrder (node->right, data);
    return node;
}

Node *buildTree(Node *node) {
    for (int i = 0; i < n; i++) node = levelOrder (node, lv[i]);
    return node;
}

void solve() {
    Node *node = NULL;
    node = buildTree (node);
    printPreOrder (node);
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