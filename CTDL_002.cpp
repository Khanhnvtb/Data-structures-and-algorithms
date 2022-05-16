//
// Created by khanh on 09/04/2021
//
/*
Cho dãy A[] gồm N số tự nhiên khác nhau và số tự nhiên K. Hãy viết chương trình liệt kê tất cả các dãy con của dãy số
A[] sao cho tổng các phần tử trong dãy con đó đúng bằng K. Dữ liệu vào trên bàn phím (n=5, K=50), 5 số dòng thứ 2 là các
phần tử dãy A:
    5                      50
    5                      10                    15                    20                    25
Các dãy con thoả mãn điều kiện tìm được liệt kê trên màn hình:
Mỗi dòng ghi lại một dãy con. Hai phần tử khác nhau của dãy con được viết cách nhau bởi một  khoảng trống.
Dòng cuối cùng ghi lại số các dãy con có tổng các phần tử đúng bằng K tìm được.
           10                    15                    25
           5                      20                    25
           5                      10                    15                    20
           3
*/
#include<bits/stdc++.h>
using namespace std;
int n,k,a[10];
int dem=0;
// bắt đầu thử từ vị trí i=0
void Try(int i,int sum,vector<int>result){
    //vòng lặp với 0 ứng với không sử dụng và 1 ứng với sử dụng
	for(int j=0;j<2;j++){
	    //tăng tổng lên a[i]*j
		sum+=a[i]*j;
		//nếu a[i] được sử dụng thì đưa a[i] vào mảng kết quả
		if(j==1){
			result.push_back(a[i]);
			//nếu tồng bằng k thì đưa ra kết quả và tăng biến đếm sau đó dừng duyệt nhánh này
			if(sum==k){
				dem++;
				for(int h=0;h<result.size();h++){
					cout<<result[h]<<" ";
				}
				cout<<endl;
				return;
			//nếu tổng lớn hơn k thì dừng duyệt nhánh này
			}else if(sum>k){
				return;
			//nếu tổng nhỏ hơn k và chưa duyệt hết mảng thì tiếp tục thử tại vị trí i+1
			}else{
				if(i<n-1) Try(i+1,sum,result);
			}
			//sau khi dùng xong a[i] thì trả lại tổng trước đó và mảng trước đó
			sum-=a[i];
			result.pop_back();
		}else{
		    //nếu chưa sử dụng và chưa duyệt hết mảng thì tiếp tục thử tại vị trí i+1
			if(i<n-1) Try(i+1,sum,result);
		}
	}
}
main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//sắp xếp lại mảng a
	sort(a,a+n);
	//khai báo mảng kết quả
	vector<int>result;
	//thử tại i=0 và tổng bằng 0
	Try(0,0,result);
	//in ra tổng số trường hợp thoả mãn
	cout<<dem;
return 0;
}
