//
// Created by khanh on 08/04/2021.
//
/*
Một số X được gọi là số khối lập phương nếu X là lũy thừa bậc 3 của số Y (X= Y3). Cho số nguyên dương N,
nhiệm vụ của bạn là tìm số khối lập phương lớn nhất bằng cách loại bỏ đi các chữ số của N. Ví dụ số 4125
ta có kết quả là 125 = 53.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤1018.
Output:
Đưa ra kết quả mỗi test theo từng dòng. Nếu không tìm được đáp án in ra -1.

Input                                Output
2
4125                                 125
976                                  -1
*/
#include<bits/stdc++.h>
using namespace std;
//tạo 1 vector a lưu các chữ số của n
vector<int>a;
//khai báo biến kết quả
long long res;
void Try(int i,long long sum){
    //vòng lặp với j=1 ứng với sử dụng a[i] và j=0 ứng với không sử dụng a[i]
    for(int j=1;j>=0;j--){
        if(j==1) {
            //số mới tạo thành khi sử dụng a[i]
            sum = sum * 10 + a[i];
            //kiểm tra xem số tạo thành có phải số khối lập phương không
            float x = cbrt(sum);
            long long y = x / 1;
            //nếu số khối lập phương lớn hơn kết quả hiện tại thì gán kết quả bằng số đó
            if (x - y == 0 && sum > res) {
                res = sum;
            }
            //nếu chưa duyệt hết vector a thì ta tiếp tục thử
            if (i < a.size() - 1){
                Try(i + 1, sum);
            }
            //trả lại số ban đầu khi chưa sử dụng a[i]
            sum/=10;
        }else{
            //nếu chưa duyệt hết vector a thì ta tiếp tục thử
            if(i<a.size()-1)
                Try(i+1,sum);
        }
    }
}
main(){
    int t;
    cin>>t;
    while(t--){
        //làm trống vector a
        a.clear();
        //nhập vào số n
        string str;
        cin>>str;
        //khởi tạo biến kết quả bằng -1
        res=-1;
        //đưa các chữ số của n vào vector a
        for(int i=0;i<str.length();i++) {
            a.push_back(str[i]-48);
        }
        //bắt đầu thử
        Try(0,0);
        //in ra kết quả
        cout<<res<<"\n";
    }
}

