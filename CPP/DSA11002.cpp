//
// Created by khanhnvtb on 07/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include<bits/stdc++.h>

using namespace std;
int n;

struct Node{
    string data;
    Node* left;
    Node* right;
};

Node* createNode(string s) {
    Node *tmp = new Node;
    tmp->data = s;
    tmp->left = tmp->right = NULL;
    return tmp;
}

bool isOperand(string s){
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

Node* convert(stack<string> st){
    queue<Node*> q;
    Node* t, *t1, *t2;
    while(!st.empty()){
        string s = st.top(); st.pop();
        if(!isOperand(s)){
            t = createNode(s);
            q.push(t);
        }
        else{
            t = createNode(s);
            t1 = q.front(); q.pop();
            t2 = q.front(); q.pop();
            t->left = t2;
            t->right = t1;
            q.push(t);
        }
    }
    return q.front();
}

int toInt(string s)
{
    int num = 0;
    if(s[0]!='-')
        for (int i=0; i<s.length(); i++)
            num = num*10 + (int(s[i])-'0');

    else{
        for (int i=1; i<s.length(); i++) num = num*10 + (int(s[i])-'0');
        num *= -1;
    }
    return num;
}

int solve(Node* node){
    if(!node) return 0;
    if(!node->left && !node->right) return toInt(node->data);
    int l = solve(node->left);
    int r = solve(node->right);
    if(node->data == "+") return l+r;
    if(node->data == "-") return l-r;
    if(node->data == "*") return l*r;
    return l/r;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        void init();
        cin >> n;
        cin.ignore();
        stack<string> st;
        while(n--){
            string s; cin >> s;
            st.push(s);
        }
        Node* root = convert(st);
        cout << solve(root) << endl;
    }
    return 0;
}