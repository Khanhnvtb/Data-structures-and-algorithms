//
// Created by KhanhNVTB on 12/04/2021.
//
/*Cho số nguyên dương N. Nhiệm vụ của bạn là tìm số K nhỏ nhất, sao cho K có đúng N ước. Input đảm bảo rằng đáp án
không vượt quá 10^18.
Input:
Dòng đầu tiên là số lượng bộ test T (T ≤  20).
Mỗi test gồm 1 số nguyên N ( 1 ≤  N ≤  1000).
Output:  Với mỗi test, in ra đáp án trên một dòng.

Input                                 Output
2
4                                     8
6                                     12
*/
#include<bits/stdc++.h>
using namespace std;
int n;
//tạo mảng số nguyên tố
int a[]={2,3,5,7,11,13,17,19,23,29,31};
long long res;
void Try(int i,long long tmp,long div){
    //nếu ước lớn hơn n thì dừng lại nếu bằng thì so sánh với res hiện tại
    if(div>n){
        return;
    }else if(div==n) {
        res = min(res, tmp);
    }
    //j ứng với số lần sử dụng số nguyên tố
    for(int j=1;;j++){
        //nếu kết quả trung gian lớn hơn kết quả hiện tại thì dừng lại
        if(tmp*a[i]>res) {
            break;
        }
        //cập nhật kết quả trung gian mới
        tmp*=a[i];
        //thử tiếp với a[i+1]
        Try(i+1,tmp,div*(j+1));
    }
}
main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        //khởi tạo kết quả là số lớn nhất kiểu long long
        res=1e18;
        Try(0,1,1);
        cout << res << endl;
    }
    return 0;
}