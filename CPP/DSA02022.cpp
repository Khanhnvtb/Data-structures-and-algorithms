//
// Created by khanh on 15/04/2021.
//
/*
Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao thông này được cho
bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j. Một
người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng
quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra. Dữ liệu vào: Dòng đầu tiên là số nguyên n – số
thành phố (n ≤ 15); n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 chiều C.
Kết quả: Chi phí mà người đó phải bỏ ra.
INPUT                                      OUTPUT
4

0 20 35 10                                 117

20 0 90 50

35 90 0 12

10 50 12 0
*/
#include <bits/stdc++.h>
using namespace std;
//mảng đánh dấu để đánh dấu những thành phố đã đi qua
bool used[20]={0};
int res=INT_MAX,n;
int a[20][20];
void Try(int i, int sum,int cnt){
    if(cnt==n-1){
        //nếu đã đi qua hết các thành phố thì quay lại thành phố 1 và cộng chi phí từ thành phố đó đến thành phố 1
        sum+=a[i][0];
        //nếu tổng chi phí nhỏ hơn kết quả hiện tại thì gán kết quả hiện tại bằng tổng đó
        if(sum<res){
            res=sum;
        }
        //dừng nhánh
        return;
    }
    //kiểm tra xem còn thành phố nào chưa đi
    for(int j=1;j<n;j++){
        if(used[j]== 0 && i!=j) {
            //cộng chi phí đến thành phố đó
            sum += a[i][j];
            //nếu tổng chi phí nhỏ hơn kết quả hiện tại thì đi tiếp
            if(sum>=res){
                return;
            }
            //đánh dấu là đã sử dụng
            used[j]=1;
            //thử với vị trí hiện tại là thành phố j
            Try (j, sum, cnt + 1);
            //trả lại chi phí khi chưa đi qua
            sum-=a[i][j];
            //đánh dấu lại là chưa đi qua
            used[j] = 0;
        }
    }
}
main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    //thử tại thành phố đầu tiên
    Try(0,0,0);
    //in ra kết quả
    cout<<res;
    return 0;
}