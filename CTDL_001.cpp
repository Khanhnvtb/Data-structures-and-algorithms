//
// Created by khanh on 09/04/2021
//
/*
Một xâu nhị phân độ dài n được gọi là thuận nghịch hay đối xứng nếu đảo ngược xâu nhị phân đó ta vẫn nhận được chính nó.
Cho số tự nhiên n (n nhập từ bàn phím). Hãy viết chương trình liệt kê tất cả các xâu nhị phân thuận nghịch có độ dài n.
Hai phần tử khác nhau của xâu thuận nghịch được ghi cách nhau một vài khoảng trống.Ví dụ với n = 4 ta tìm được 4 xâu nhị
phân thuận nghịch như dưới đây.
        0                      0                      0                      0
        0                      1                      1                      0
        1                      0                      0                      1
        1                      1                      1                      1
*/
#include<bits/stdc++.h>
using namespace std;
int n,OK;
int a[20];
//ham khởi tạo cấu hình đầu tiên
void khoitao(){
	for(int i=0;i<n;i++){
		a[i]=0;
	}
}
//hàm in ra cấu hình hiện tại
void in(){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}
void sinh(){
	if(n%2==0){
	    //khơi tạo cấu hình đầu tiên
		khoitao();
		while(OK==0){
		    //in ra cấu hình đầu tiên
			in();
			OK=1;
			//sinh xâu nhị phân kế tiếp trong khoảng từ đầu mảng đến vị trí n/2-1
			for(int i=n/2-1;i>=0;i--){
				if(a[i]==0){
					a[i]=1;
					for(int j=i+1;j<n/2;j++){
						a[j]=0;
					}
					OK=0;
					break;	
				}
			}
			//sinh xâu nhị phân kế tiếp trong khoảng từ cuối mảng đến vị trí n/2
			for(int i=n/2;i<n;i++){
				if(a[i]==0){
					a[i]=1;
					for(int j=n/2;j<i;j++){
						a[j]=0;
					}
					break;
				}
			}
		}
	}else{
	    //khởi tạo cấu hình đầu tiên
		khoitao();
		//in ra cấu hình đầu tiên
		in();
		while(OK==0){
			OK=1;
			//sinh xâu nhị phân kế tiếp trong khoảng từ đầu mảng đến vị trí n/2-1
			for(int i=n/2-1;i>=0;i--){
				if(a[i]==0){
					a[i]=1;
					for(int j=i+1;j<n/2;j++){
						a[j]=0;
					}
					OK=0;
					break;	
				}
			}
			//sinh xâu nhị phân kế tiếp trong khoảng từ cuối mảng đến vị trí n/2
			for(int i=n/2+1;i<n;i++){
				if(a[i]==0){
					a[i]=1;
					for(int j=n/2+1;j<i;j++){
						a[j]=0;
					}
					break;
				}
			}
			//gán vị trí a[n/2] lần lượt bằng 0 và 1
			for(int k=0;k<2;k++){
				a[n/2]=k;
				if(OK==0){
				    //in ra cấu hình hiện tại
					in();
				}
			}
		}	
	}
}
main(){
	cin>>n;
	OK=0;
    sinh();
return 0;
}

