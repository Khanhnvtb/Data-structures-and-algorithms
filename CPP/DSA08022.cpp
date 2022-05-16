//
// Created by khanh on 5/21/2021.
//

#include <bits/stdc++.h>
using namespace std;
long n, sum;
int check, a[100005];
int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n);
        if (sum % 3 == 0) {
            if (a[n - 1] == 0) {
                cout << "0" << "\n";
            } else {
                for (int i = n - 1; i >= 0; i --) {
                    cout << a[i];
                }
            }
        } else {
            queue <int> div1;
            queue <int> div2;
            for (int i = 0; i < n; i ++) {
                if (div1.size() < 2 && a[i] % 3 == 1) {
                    div1.push(a[i]);
                    a[i] = - 1;
                } else if (div2.size() < 2 && a[i] % 3 == 2) {
                    div2.push(a[i]);
                    a[i] = - 1;
                } else if (div1.size() == 2 && div2.size() == 2) {
                    break;
                }
            }
            priority_queue <int, vector <int>, less <int> > q;
            for (int i = 0; i < n; i ++) {
                if (a[i] != - 1) {
                    q.push(a[i]);
                }
            }
            if (sum % 3 == 1) {
                if (div1.empty() && div2.size() != 2) {
                    cout << "-1";
                } else {
                    if (! div1.empty()) {
                        div1.pop();
                        q.push(div1.front());
                        while (! div2.empty()) {
                            q.push(div2.front());
                            div2.pop();
                        }
                    }
                }
            } else if (sum % 3 == 2) {
                if (div1.size() != 2 && div2.empty()) {
                    cout << "-1";
                } else if (! div2.empty()) {
                    div2.pop();
                    q.push(div2.front());
                    while (! div1.empty()) {
                        q.push(div1.front());
                        div1.pop();
                    }
                }
            }
            if (q.empty()) {
                cout << "-1";
            } else {
                while (! q.empty()) {
                    cout << q.top();
                    q.pop();
                }
            }
        }
        cout << endl;
    }
    return 0;
}