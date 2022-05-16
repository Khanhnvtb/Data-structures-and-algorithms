//
// Created by khanh on 10/04/2021.
//
/*
Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng
bằng X. Các số trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không
giảm các số. Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:
[2, 2, 2, 2], [2, 2, 4], [2, 6], [4, 4], [8].
Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và X; dòng tiếp theo đưa vào
N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, X, A[i] thỏa mãn ràng buộc: 1≤T ≤10; 1≤X, A[i]≤100. N ≤ 20.
Output:
Đưa ra kết quả mỗi test theo từng dòng. Mỗi đường tổ hợp được bao bởi cặp ký tự [, ]. Đưa ra -1 nếu không có tổ hợp nào
thỏa mãn yêu cầu bài toán.
Input                            Ouput
1
4 8
2  4  6  8
2  4  6  8                       [2 2 2 2][2 2 4][2 6][4 4][8]
*/
#include <bits/stdc++.h>
using namespace std;
int check;
int n,x,a[20];
//thử tại vị trí i với sum và mảng kết quả hiện tại
void Try(int i,int sum,vector<int>res){
    //j = 1 ứng với sử dụng và 0 ứng với k sử dụng
    for(int j=1;j>=0;j--){
        if(j==1){
            //sử dụng thì đẩy vào mảng kết quả và tăng tổng
            res.push_back(a[i]);
            sum+=a[i];
            //nếu tổng bằng x đánh dấu đã đúng và in ra kết quả tổng lớn hơn x thì dừng lại và nhỏ hơn x thì thử tiếp
            if(sum==x){
                check=1;
                cout<<"[";
                for(int k=0;k<res.size()-1;k++){
                    cout<<res[k]<<" ";
                }
                cout<<res[res.size()-1]<<"]";
                return;
            }else if(sum>x){
                return;
            }else{
                Try(i,sum,res);
            }
            //trả lại sum và mảng kết quả trước đó để chuyển sang trường hợp không sử dụng
            sum-=a[i];
            res.pop_back();
        }else{
            //không sử dụng thì thử tiếp với trường hợp i+1
            if(i<n-1){
                Try(i+1,sum,res);
            }
        }
    }
}
main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>x;
        //khởi tạo biến kiểm tra sai
        check=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        //khởi tạo vector kết quả
        vector<int>res;
        //bắt đầu thử tại vị trí 0 với tổng bằng 0 và mảng kết quả trống
        Try(0,0,res);
        //nếu không có kết quả in ra -1
        if(check==0){
            cout<<"-1";
        }
        cout<<endl;
    }
}
