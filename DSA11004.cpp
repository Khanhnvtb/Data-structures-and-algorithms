//
// Created by khanhnvtb on 07/06/2021.
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
void make_node(Node* node, int b, int c) {
    if (c == 'L')
        node->left = new Node (b);
    else
        node->right = new Node (b);
}
void findNode(Node* node, int a, int b, int c) {
    if (node == NULL) return;
    if (node->data == a) make_node (node, b, c);
    else {
        findNode (node->left, a, b, c);
        findNode (node->right, a, b, c);
    }
}

void print(Node* node) {
    if (node == NULL) return;
    queue <Node *> q;
    q.push (node);
    while (!q.empty ()) {
        Node *tmp = q.front ();
        cout << tmp->data << " ";
        q.pop ();
        if (tmp->left != NULL)
            q.push (tmp->left);
        if (tmp->right != NULL)
            q.push (tmp->right);
    }
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
            if (node == NULL) {
                node = new Node (a);
                make_node (node, b, c);
            } else findNode (node, a, b, c);
        }
        print (node);
        cout << endl;
    }
    return 0;
}