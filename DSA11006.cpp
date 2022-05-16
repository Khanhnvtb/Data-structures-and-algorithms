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
void findNode(Node *node, int a, int b, int c) {
    if (node == NULL) return;
    if (node->data == a) {
        makeNode (node, b, c);
    } else {
        findNode (node->left, a, b, c);
        findNode (node->right, a, b, c);
    }
}
void printSpiral_order(Node* node) {
    if (node == NULL) return;
    stack <Node *> s1;
    stack <Node *> s2;
    s1.push (node);
    while (!s1.empty () || !s2.empty ()) {
        while (!s1.empty ()) {
            Node *tmp = s1.top ();
            s1.pop ();
            cout << tmp->data << " ";
            if (tmp->right) s2.push (tmp->right);
            if (tmp->left) s2.push (tmp->left);
        }
        while (!s2.empty ()) {
            Node *tmp = s2.top ();
            s2.pop ();
            cout << tmp->data << " ";
            if (tmp->left) s1.push (tmp->left);
            if (tmp->right) s1.push (tmp->right);
        }
    }
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
            if (node == NULL) {
                node = new Node (a);
                makeNode (node, b, c);
            } else {
                findNode (node, a, b, c);
            }
        }
        printSpiral_order (node);
        cout << endl;
    }
    return 0;
}