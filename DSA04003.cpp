//
// Created by KhanhNVTB on 12/04/2021.
//
/*
Cho số nguyên dương n. Hãy cho biết có bao nhiêu dãy số nguyên dương có tổng các phần tử trong dãy bằng n.

Dữ liệu vào: dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ liệu ghi một số nguyên dương n duy nhất không qua 1018.

Kết quả: Mỗi bộ dữ liệu ghi ra một số nguyên duy nhất là số dư của kết quả tìm được khi chia cho 123456789.
Input                                   Output
1

3                                        4
*/
#include<bits/stdc++.h>
using namespace std;
long m=123456789;
long long n;
//hàm tính luỹ thừa
long long power(long n){
    if(n==0) {
        return 1;
    }else if(n==1){
        return 2;
    }
    if(n%2==0) {
        return (power(n / 2) % m * power(n / 2) % m) % m;
    }else {
        return ((power(n / 2) % m * power(n / 2) % m) % m * 2) % m;
    }
}
main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        //số dãy bằng 2^(n-1)
        cout<<power(n-1)<<"\n";
    }
    return 0;
}
