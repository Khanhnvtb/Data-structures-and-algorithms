//
// Created by khanhnvtb on 08/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;
vector <string> res;
string str;
map <string, int> mm;
bool check(string str) {
    if (str.length () == 1 || str =="") return 0;
    stack <char> s;
    for (int i = 0; i < str.length (); i++) {
        if (str[i] == '(') s.push (str[i]);
        else if (str[i] == ')') {
            if (s.empty ()) return false;
            else s.pop ();
        }
    }
    if (s.empty ()) return true;
    else return false;
}
void solve() {
    queue <string> q;
    q.push (str);
    int flag = 0;
    mm[str]=1;
    while (!q.empty ()) {
        string tmp = q.front ();
        q.pop ();
        if (check (tmp)) {
            flag = 1;
            res.push_back (tmp);
        }
        if (flag == 0) {
            for (int i = 0; i < tmp.length (); i++) {
                if (tmp[i] == '(' || tmp[i] == ')') {
                    string s1 = tmp;
                    s1.erase (s1.begin () + i);
                    if(mm[s1]==0){
                        mm[s1]=1;
                        q.push (s1);
                    }
                }
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> str;
        solve ();
        if (res.size () == 0) cout << -1;
        else {
            sort (res.begin (), res.end ());
            for (int i = 0; i < res.size (); i++) {
                cout << res[i] << " ";
            }
        }
        cout << endl;
        res.clear ();
        mm.clear ();
    }
    return 0;
}
