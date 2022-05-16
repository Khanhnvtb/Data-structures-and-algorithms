//
// Created by khanh on 10/04/2021.
//
/*
Cho danh sách liên kết đơn lưu giữ các số nguyên được quản lý bởi con trỏ First. Viết chương trình con lọc tất cả các
phần tử có giá trị trùng nhau trong danh sách liên kết đơn First, chỉ để lại 1 phần tử đại diện cho nhóm trùng. Sau khi
lọc xong, liệt kê các phần tử  trong danh sách liên kết đơn First.
Ví dụ: Ta có Input :
12 : là số lượng phân tử trong danh sách
1 1 1 4  5 1 4  7 7 8 1 9 : là số phần tử
Output : 1 4 5 7 8 9
*/
#include <bits/stdc++.h>
using namespace std;
main(){
    long n;
    cin>>n;
    //nhập vào mảng a và sao chép mảng a vào vector b
    long a[n];
    vector<long>b;
    for(long i=0;i<n;i++){
        cin>>a[i];
        b.push_back(a[i]);
    }
    //sắp xếp vector b
    sort(b.begin(),b.end());
    //tìm các số xuất hiện trong b
    for(long i=1;i<b.size();i++){
        if(b[i]==b[i-1]){
            b.erase(b.begin()+i);
            i=0;
        }
    }
    //vòng lặp cho đến khi kích thước của b bằng 0
    while(b.size()>0){
        //nếu xuất hiện b[j] trong a[i] thì in ra a[i] và xoá phần tử đó khỏi vector b
        for(long i=0;i<n;i++){
            for(long j=0;j<b.size();j++){
                if(a[i]==b[j]){
                    cout<<a[i]<<" ";
                    b.erase(b.begin()+j);
                }
            }
        }
    }
    return 0;
}

