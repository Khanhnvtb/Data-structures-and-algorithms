//
// Created by khanh on 5/15/2021.
//

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    cin.ignore();
    int a[1005][1005];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        string str;
        getline(cin, str);
        str += " ";
        int x = 0;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] != ' ') {
                x = x * 10 + (int) (str[j] - '0');
            } else {
                a[i][x] = 1;
                x = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}