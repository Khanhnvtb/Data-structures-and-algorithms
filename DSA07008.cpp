//
// Created by KhanhNVTB on 12/05/2021.
//
#include <bits/stdc++.h>
using namespace std;
int comp(char x){
    if(x=='('){
        return 1;
    }else if(x=='+' || x=='-'){
        return 2;
    }else if(x=='*' || x=='/'){
        return 3;
    }else{
        return 4;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        stack <char> stk;
        for (int i = 0 ; i < str.length () ; i++) {
            if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122) {
                cout << str[i];
            } else if (str[i] == '(') {
                stk.push (str[i]);
            } else if (str[i] == ')') {
                while (stk.size () > 0 && stk.top () != '(') {
                    cout << stk.top ();
                    stk.pop ();
                }
                stk.pop ();
            } else {
                while (stk.size () > 0 && comp (stk.top ()) >= comp (str[i])) {
                    cout << stk.top ();
                    stk.pop ();
                }
                stk.push (str[i]);
            }
        }
        while (stk.size () > 0 && stk.top () != '(') {
            cout << stk.top ();
            stk.pop ();
        }
        cout << endl;
    }
    return 0;
}
