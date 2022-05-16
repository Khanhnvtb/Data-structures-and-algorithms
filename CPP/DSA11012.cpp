//
// Created by khanhnvtb on 08/06/2021.
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
void findNode(Node *node, int a, int b, int c) {
    if (!node) return;
    if (node->data == a) makeNode (node, b, c);
    else {
        findNode (node->left, a, b, c);
        findNode (node->right, a, b, c);
    }
}
int indenticalTree(Node *T1, Node *T2) {
    if (!T1 && !T2) return 1;
    if (T1 && T2) {
        return (T1->data == T2->data && indenticalTree (T1->left, T2->left) && indenticalTree (T1->right, T2->right));
    }
    return 0;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node *T1 = NULL;
        Node *T2 = NULL;
        int a, b;
        char c;
        while (n--) {
            cin >> a >> b >> c;
            if (!T1) {
                T1 = new Node (a);
                makeNode (T1, b, c);
            } else findNode (T1, a, b, c);
        }
        cin >> n;
        while (n--) {
            cin >> a >> b >> c;
            if (!T2) {
                T2 = new Node (a);
                makeNode (T2, b, c);
            } else findNode (T2, a, b, c);
        }
        cout << indenticalTree (T1, T2) << endl;
    }
    return 0;
}