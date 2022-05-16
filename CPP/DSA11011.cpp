//
// Created by khanhnvtb on 08/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;
int n;
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
int fullBinaryTree(Node *node) {
    queue <Node *> q;
    q.push (node);
    while (!q.empty ()) {
        Node *tmp = q.front ();
        q.pop ();
        if (!tmp->left && tmp->right ) return 0;
        if (tmp->left && !tmp->right) return 0;
        if (tmp->left && tmp->right) {
            q.push (tmp->left);
            q.push (tmp->right);
        }
    }
    return 1;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int a, b;
        char c;
        Node *node = NULL;
        while (n--) {
            cin >> a >> b >> c;
            if (!node) {
                node = new Node (a);
                makeNode (node, b, c);
            } else findNode (node, a, b, c);
        }
        cout << fullBinaryTree (node) << endl;
    }
    return 0;
}