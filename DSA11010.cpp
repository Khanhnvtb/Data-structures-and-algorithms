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
void makeNode(Node* node, int b, int c) {
    if (c == 'L') node->left = new Node (b);
    else node->right = new Node (b);
}
void findNode(Node* node, int a, int b, int c) {
    if (!node) return;
    if (node->data == a) makeNode (node, b, c);
    else {
        findNode (node->left, a, b, c);
        findNode (node->right, a, b, c);
    }
}
bool checkLevel(Node* node) {
    if (!node)
        return true;
    queue <pair <Node *, int> > q;
    q.push ({node, 0});
    int result = INT_MAX;
    while (!q.empty ()) {
        int level = q.front ().second + 1;
        Node *tmp = q.front ().first;
        q.pop ();
        if (!tmp->left && !tmp->right) {
            if (result == INT_MAX) {
                result = level;
            } else {
                if (level != result) return false;
            }
        }
        if (tmp->left) q.push ({tmp->left, level});
        if (tmp->right) q.push ({tmp->right, level});

    }
    return true;
}
bool fullBinaryTree(Node *node) {
    queue <Node *> q;
    q.push (node);
    while (!q.empty ()) {
        Node *tmp = q.front ();
        q.pop ();
        if (!tmp->left && tmp->right) return false;
        if (tmp->left && !tmp->right) return false;
        if (tmp->left && tmp->right) {
            q.push (tmp->left);
            q.push (tmp->right);
        }
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node *node = NULL;
        int a, b;
        char c;
        while (n--) {
            cin >> a >> b >> c;
            if (!node) {
                node = new Node (a);
                makeNode (node, b, c);
            } else findNode (node, a, b, c);
        }
        if (checkLevel (node) && fullBinaryTree (node)) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << endl;
    }
    return 0;
}