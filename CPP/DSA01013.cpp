//
// Created by KhanhNVTB on 12/04/2021.
//
/*
Số nhị phân được xem là cách mặc định biểu diễn các số. Tuy nhiên, trong nhiều ứng dụng của điện tử và truyền thông
lại dùng một biến thể của mã nhị phân đó là mã Gray. Mã Gray độ dài n có mã đầu tiên là n số 0, mã kế tiếp của nó
là một xâu nhị phân độ dài n khác biệt với xâu trước đó một bít. Ví dụ với n=3 ta có 23 mã Gray như sau: 000, 001,
011, 010, 110, 111, 101, 100. Hãy viết chương trình chuyển đổi một xâu mã Gray X có độ dài n thành một xâu mã nhị
phân.
Input::
Dòng đầu tiên là số lượng test T.
T dòng kế tiếp ghi lại mỗi dòng một test. Mỗi test là một xâu mã Gray độ dài n.
T, n thỏa mãn ràng buộc: 1≤T, n≤10.
Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input                                     Output
2

01101                                     01001

01011                                     01101
*/
#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        //tạo 1 vector kết quả
        vector<int>res;
        //bit đầu tiên của mã nhị phân cũng là bit đầu tiên của mã gray
        res.push_back(str[0]-48);
        //các bit i còn lại là tổng không nhớ giữa bit i-1 của mã gray và bit i của mã nhị phân
        for(int i=1;i<str.length();i++){
            if(res[i-1]+(str[i]-48)==1){
                res.push_back(1);
            }else{
                res.push_back(0);
            }
        }
        //in ra kết quả
        for(int i=0;i<res.size();i++){
            cout<<res[i];
        }
        cout<<endl;
    }
}
