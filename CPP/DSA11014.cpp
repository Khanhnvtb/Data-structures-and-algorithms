//
// Created by khanhnvtb on 07/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include<iostream>
#include<map>
using namespace std;

struct Node {
    int data;
    Node* left, * right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

map<int, Node*> mp;
int n;

Node* build() {
    Node* root = NULL;
    long long a, b;	char c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (mp.find(a) == mp.end()) {
            mp[a] = new Node(a);
            if (root == NULL)
                root = mp[a];
        }

        if (c == 'L') {
            mp[a]->left = new Node(b);
            mp[b] = mp[a]->left;
        }
        else {
            mp[a]->right = new Node(b);
            mp[b] = mp[a]->right;
        }
    }
    return root;
}

void solve(Node* node, long long& sum) {
    if (node->right != NULL) {
        if (node->right->left == NULL && node->right->right == NULL)
            sum += node->right->data;
        else solve(node->right, sum);
    }
    if (node->left != NULL) solve(node->left, sum);
}

int main() {
    int t;	cin >> t;
    while (t--) {
        cin >> n;

        Node* root = build();

        long long sum = 0;
        solve(root, sum);
        cout << sum << endl;
        mp.clear();
    }
    return 0;
}