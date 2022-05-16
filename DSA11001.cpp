//
// Created by khanhnvtb on 07/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;
string str;
void init() {
    cin >> str;
}
struct et {
    char val;
    et *left, *right;
};
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') return true;
    return false;
}
et* newNode(char c) {
    et *tmp = new et;
    tmp->left = tmp->right = NULL;
    tmp->val = c;
    return tmp;
}
et* constructTree() {
    stack <et *> s;
    et *t, *t1, *t2;
    for (int i = 0; i < str.length (); i++) {
        if (!isOperator (str[i])) {
            t = newNode (str[i]);
            s.push (t);
        } else {
            t = newNode (str[i]);
            t1 = s.top ();
            s.pop ();
            t2 = s.top ();
            s.pop ();
            t->right = t1;
            t->left = t2;
            s.push (t);
        }
    }
    return s.top ();
}
void print(et* res) {
    if (res) {
        print (res->left);
        cout << res->val;
        print (res->right);
    }
}
void solve() {
    et *res = constructTree ();
    print (res);
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