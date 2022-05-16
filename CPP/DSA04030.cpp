//
// Created by khanhnvtb on 21/06/2021.
//
/* Ý tưởng: 
*/
//khuyến khích thực hiện thực hành trước khi đi vào giải pháp.

#include <bits/stdc++.h>
const long long MOD = 1000000000000007ll;
using namespace std;

struct mat {
    long long a[4][4];
} a, b;
int t, n;
long long F[5], T[5];

long long mul(long long a, long long b) {
    long long c = 0;
    while (b) {
        if (b & 1) {
            c += a;
            if (c >= MOD) c -= MOD;
        }
        a += a; if (a >= MOD) a -= MOD;
        b /= 2;
    }
    return c;
}

mat operator * (mat a, mat b) {
    mat c;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) {
            c.a[i][j] = 0;
            for(int k = 0; k < 4; k++)
                c.a[i][j] = (c.a[i][j] + mul(a.a[i][k], b.a[k][j])) % MOD;
        }
    return c;
}

mat POW(int p) {
    if (p == 1) return a;
    mat x = POW(p / 2);
    x = x * x;
    if (p & 1) x = x * a;
    return x;
}

int main() {
    scanf("%d", &t);
    a.a[0][0] = a.a[0][1] = a.a[1][1] = a.a[1][2] = a.a[1][3] = a.a[2][1] = a.a[3][2] = 1;
    F[1] = 1; F[2] = 3; F[3] = 6; T[1] = 1; T[2] = 2; T[3] = 3;
    while (t--) {
        scanf("%d", &n);
        if (n <= 3) printf("%lld\n", F[n]);
        else {
            b = POW(n - 2);
            printf("%lld\n", (F[2] * b.a[0][0] + T[3] * b.a[0][1] + T[2] * b.a[0][2] + T[1] * b.a[0][3]) % MOD);
        }
    }
    return 0;
}