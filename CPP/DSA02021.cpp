#include<bits/stdc++.h>
using namespace std;
long long n;
int cnt;
long find(int cnt,long long k) {
    if ( cnt == 0 ) {
        return k;
    } else {
        n /= 2;
        cnt --;
        if ( k >= n ) {
            k -= n;
            if ( k == 1 || k == 0 ) {
                return find ( cnt, n );
            } else {
                return find ( cnt, k - 1 );
            }
        } else {
            return find ( cnt, k );
        }
    }
}
main() {
    int t;
    cin >> t;
    while ( t -- ) {
        string str;
        cin >> str;
        long long k;
        cin >> k;
        if ( k <= str.length ( ) ) {
            cout << str[k - 1] << "\n";
        } else {
            n = str.length ( ), cnt = 0;
            char s[n + 1];
            for ( int i = 1 ; i <= n ; i ++ ) {
                s[i] = str[i - 1];
            }
            while ( n < k ) {
                n *= 2;
                cnt ++;
            }
            cout << s[find ( cnt, k )] << "\n";
        }
    }
    return 0;
}