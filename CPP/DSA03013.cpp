//
// Created by KhanhNVTB on 12/04/2021.
//
/*
Cho xâu ký tự S bao gồm các ký tự in thường và số D. Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại các ký
tự trong S để tất cả các ký tự giống nhau đều có khoảng cách là D hay không? Đưa ra 1 nếu có thể sắp đặt lại các
ký tự trong S thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.
Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số D; dòng tiếp theo là xâu S.
T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000; 1≤D≤100.
Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input                             Output
2

2
ABB                               1

2
AAA                               -1
*/
#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--){
        int d;
        cin>>d;
        string str;
        cin>>str;
        //tạo mảng đếm số lần xuất hiện các ký tự
        int a[130]={0};
        //nếu xuất hiện kí tự nào thì tăng số lần xuất hiện của ký tự đó
        for(int i=0;i<str.length();i++){
            a[str[i]]++;
        }
        //sắp xếp lại số lần xuất hiện của các ký tự
        sort(a,a+130);
        int res=1;
        /*
        khoảng cách giữa các ký tự giống nhau là d nên số các ký tự khác số lần xuất hiện nhiều nhất phải nhỏ hơn số
        khoảng trống sau khi đặt các ký tự xuất hiện nhiều nhất cách nhau d ký tự
        */
        if((a[129]-1)*(d-1)>str.length()-a[129]){
            res=-1;
        }
        //in ra kết quả
        cout<<res<<endl;
    }
    return 0;
}
