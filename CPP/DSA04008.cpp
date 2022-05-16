#include <bits/stdc++.h>
using namespace std;
long m=1e9+7;
void multiply(long F[2][2], long M[2][2]);
void power(long F[2][2], long n);
long fib(long n)
{
    long F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
 
    return F[0][0]%m;
}
void power(long F[2][2], long n)
{
    if(n == 0 || n == 1)
       return;
    long M[2][2] = {{1, 1}, {1, 0}};
     
    power(F, n / 2);
    multiply(F, F);
     
    if (n % 2 != 0)
        multiply(F, M);
}
 
void multiply(long F[2][2], long M[2][2])
{
    long x = (F[0][0]%m * M[0][0]%m + F[0][1]%m * M[1][0]%m)%m;
    long y = (F[0][0]%m * M[0][1]%m + F[0][1]%m * M[1][1]%m)%m;
    long z = (F[1][0]%m * M[0][0]%m + F[1][1]%m * M[1][0]%m)%m;
    long w = (F[1][0]%m * M[0][1]%m + F[1][1]%m * M[1][1]%m)%m;
     
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
 
int main()
{	int t;
	cin>>t;
	while(t--){
    	long n;
    	cin>>n;
    	cout << fib(n)<<"\n";
    	getchar();
    }
    return 0;
}
