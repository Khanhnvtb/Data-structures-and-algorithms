//
// Created by khanhnvtb on 19/06/2021.
//
/* Ý tưởng: 
*/
//khuyến khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

int n, pre;

struct Node {
    int data;
    Node *left, *right;

    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

void makeNode(Node *&node, int data) {
    if (!node) {
        node = new Node (data);
        return;
    }
    if (data < node->data) makeNode (node->left, data);
    else makeNode (node->right, data);
}

int maxDepth(Node* node) {
    if (node == NULL) return 0;
    int lDepth = maxDepth (node->left);
    int rDepth = maxDepth (node->right);
    if (lDepth > rDepth) return (lDepth + 1);
    else return (rDepth + 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        Node *node = NULL;
        for (int i = 0; i < n; i++) {
            cin >> pre;
            makeNode (node, pre);
        }
        cout << maxDepth (node) - 1 << endl;
    }
    return 0;
}