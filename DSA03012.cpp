//
// Created by KhanhNVTB on 12/04/2021.
//
/*
Cho xâu ký tự S bao gồm các ký tự in thường. Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại các ký tự trong S để
hai ký tự giống nhau đều không kề nhau hay không? Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S thỏa mãn yêu cầu bài
toán, ngược lại đưa ra -1.
Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự S được viết trên một dòng.
T, S thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000.
Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input                               Output
3
geeksforgeeks                       1
bbbabaaacd                          1
bbbbb                               -1
*/
#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--){
        //nhập vào xâu
        string str;
        cin>>str;
        //khai báo mảng đếm và gán tất cả bằng 0
        int a[130]={0};
        //đếm số lần xuất hiện của mỗi phần tử
        for(int i=0;i<str.length();i++){
            a[str[i]]++;
        }
        //sắp xếp lại mảng thì phần tử cuối cùng là số lần xuất hiện lớn nhất của 1 phần tử
        sort(a,a+130);
        /*
         nếu độ dài của mảng là số chẵn thì số lần xuất hiện lớn nhất không lớn hơn tổng số lần xuất hiện của các phần
         tử còn lại thì đúng còn không thì sai
         nếu độ dài của mảng là số lẻ thì số lần xuất hiện lớn nhất không lớn hơn tổng số lần xuất hiện của các phần tử
         còn lại cộng 1 thì đúng còn không thì sai
         */
        if(str.length()%2==0){
            if(a[129]<=str.length()/2){
                cout<<"1";
            }else{
                cout<<"-1";
            }
        }else{
            if(a[129]<=str.length()/2+1){
                cout<<"1";
            }else{
                cout<<"-1";
            }
        }
        cout<<endl;
    }
    return 0;
}