//
// Created by KhanhNVTB on 11/04/2021.
//
#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[101];
void Try(int i,vector<int>b, int dem){
    for(int j=1;j>=0;j--){
        //sử dụng a[i] khi a[i] lớn hơn phần tử cuối của vector
        if(j==1 && a[i]>b[b.size()-1]){
            //tăng đếm
            dem++;
            //đẩy a[i] vào cuối vector
            b.push_back(a[i]);
            //nếu đã đủ bộ k số thì tăng số cặp lên và dừng nhánh
            if(dem==k){
                cnt++;
                return;
            }else{
                //nếu chưa đủ thì thử tiếp
                if(i<=n-dem){
                    Try(i+1,b,dem);
                }
            }
            //trả lại vector trước đó và đếm trước đó
            b.pop_back();
            dem--;
        }else if(j==0){
            //nếu không sử dụng a[i] thì tiếp tục thử
            if(i<=n-dem){
                Try(i+1,b,dem);
            }
        }
    }
}
main(){
    cin>>n>>k;
    cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //khai báo vector để lưu trữ bộ k số tạo thành
    vector<int>b;
    //duyệt từ vị trí 0 đến vị trí tối đa mà còn có thể ghép thành cặp k số
    for(int i=0;i<=n-k;i++){
        //gán b[0]=-1 để các phần tử của mảng luôn lớn hơn b[0]
        b.push_back(-1);
        //thử tại vị trí i với vector b và đếm bằng 0
        Try(i,b,0);
        //xoá sạch vector b
        b.clear();
    }
    //in ra kết quả
    cout<<cnt<<"\n";
    return 0;
}


