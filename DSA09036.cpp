//
// Created by khanhnvtb on 14/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

struct data {
    string father, son;
    int ageF, ageS;
};

int x;
data a[102];

int cmp(data i, data j) {
    if (i.ageS < j.ageS) return 0;
    else if (i.ageS == j.ageS) {
        if (i.son > j.son) return 0;
    }
    return 1;
}

void init() {
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> a[i].father >> a[i].son >> a[i].ageF;
    }
}

void solve() {
    queue <pair <string, int> > q;
    q.push ({"Ted", 100});
    while (!q.empty ()) {
        string tmp = q.front ().first;
        int age = q.front ().second;
        q.pop ();
        for (int i = 0; i < x; i++) {
            if (a[i].father == tmp) {
                a[i].ageS = age - a[i].ageF;
                q.push ({a[i].son, a[i].ageS});
            }
        }
    }
    sort (a, a + x, cmp);
}

void print(int t) {
    cout << "DATASET " << t << endl;
    for (int i = 0; i < x; i++) {
        cout << a[i].son << " " << a[i].ageS << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        init ();
        solve ();
        print (i);
    }
    return 0;
}