
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
void insert(Node* node, int a, int b, int c) {        // tìm node cha
    if (node == NULL) return;
    if (node->data == a) make_node (node, b, c);        // nếu tìm thấy node cha
    else {
        insert (node->left, a, b, c);                // tìm bên trái
        insert (node->right, a, b, c);                // tìm bên phải
    }
}
int checkLevel(Node* node) {
    if (!node)
        return 1;
    queue <pair <Node *, int> > q;
    q.push ({node, 0});
    int result = INT_MAX;
    while (!q.empty ()) {
        int level = q.front ().second + 1;
        Node *tmp = q.front ().first;
        q.pop();
        if (!tmp->left && !tmp->right) {
            if (result == INT_MAX) {
                result = level;
            } else {
                if (level != result) return 0;
            }
        }
        if (tmp->left) q.push ({tmp->left, level});
        if (tmp->right) q.push ({tmp->right, level});

    }
    return 1;
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
            } else insert (node, a, b, c);
        }
        cout << checkLevel (node) << endl;
    }
    return 0;
}