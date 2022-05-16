//
// Created by khanhnvtb on 14/06/2021.
//
/* Ý tưởng: 
*/
//khuyên khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
using namespace std;

long swapCount(string chars) {
    int countLeft = 0, countRight = 0;
    int swap = 0, imbalance = 0;
    for (int i = 0; i < chars.length (); i++) {
        if (chars[i] == '[') {
            countLeft++;
            if (imbalance > 0) {
                swap += imbalance;
                imbalance--;
            }
        } else if (chars[i] == ']') {
            countRight++;
            imbalance = (countRight - countLeft);
        }
    }
    return swap;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << swapCount (str) << endl;
    }
}