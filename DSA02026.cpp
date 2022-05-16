//
// Created by khanhnvtb on 16/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

string str, tmp;
vector <string> res;
int state;
bool isOperator(char c) {
    if (c == '+' || c == '-') return true;
    return false;
}

int toInt(char x, char y) {
    int tmp = (x - 48) * 10 + (y - 48);
    return tmp;
}

bool check(string s) {
    int a, b, c;
    a = toInt (s[0], s[1]);
    b = toInt (s[5], s[6]);
    c = toInt (s[10], s[11]);
    if (s[3] == '+' && a + b == c) return true;
    if (s[3] == '-' && a - b == c) return true;
    return false;
}

void init() {
    getline (cin, str);
}

void Try(int i) {
    if(state==1) return;
    if (i == 0 || i == 5 || i == 10) {
        if (str[i] == '?') {
            for (int j = 49; j < 58; j++) {
                char c = j;
                tmp += c;
                Try (i + 1);
                tmp.pop_back ();
            }
        } else {
            tmp += str[i];
            Try (i + 1);
            tmp.pop_back ();
        }
    } else if (i == 1 || i == 6) {
        if (str[i] == '?') {
            for (int j = 48; j < 58; j++) {
                char c = j;
                tmp += c;
                Try (i + 1);
                tmp.pop_back ();
            }
        } else {
            tmp += str[i];
            Try (i + 1);
            tmp.pop_back ();
        }
    } else if (i == 11) {
        if (str[i] == '?') {
            for (int j = 48; j < 58; j++) {
                char c = j;
                tmp += c;
                if (check (tmp)) {
                    state=1;
                    cout<<tmp;
                    return;
                }
                tmp.pop_back ();
            }
        } else {
            tmp += str[i];
            if (check (tmp)) {
                state=1;
                cout<<tmp;
                return;
            }
            tmp.pop_back ();
        }
    } else if (i == 3) {
        if (isOperator (str[i])) {
            tmp += str[i];
            Try (i + 1);
            tmp.pop_back ();
        } else {
            tmp += '+';
            Try (i + 1);
            tmp.pop_back ();
            tmp += '-';
            Try (i + 1);
            tmp.pop_back ();
        }
    } else {
        tmp += str[i];
        Try (i + 1);
        tmp.pop_back ();
    }
}

void solve() {
    state = 0;
    if (str[3] == '/' || str[3] == '*') return;
    if (str[0] == '0' || str[5] == '0' || str[10] == '0') return;
    if (check (str)) {
        state = 1;
        cout << str;
        return;
    }
    tmp = "";
    Try (0);
}

void print() {
    if (state == 0) {
        cout << "WRONG PROBLEM!";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore ();
    while (t--) {
        init ();
        solve ();
        print ();
    }
    return 0;
}