//
// Created by khanh on 09/04/2021
//
/*
Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân tiếp theo của X[]. Ví dụ X[] =”010101” thì xâu nhị
phân tiếp theo của X[] là “010110”.
Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤10^3.
Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input                           Output
2

010101                          010110

111111                          000000
*/
#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
	    //nhập vào xâu nhị phân đầu vào
		string str;
		cin>>str;
		//khai báo biến kiểm tra
		int check=-1;
		//duyệt từ cuối mảng đến phần tử 0 đầu tiên thì gán lại bằng 1 sau đó gán tất cả phần tử phía sau bằng 0
		for(int i=str.length()-1;i>=0;i--){
			if(str[i]=='0'){
				str[i]='1';
				//thay đổi biến kiểm tra và  dừng vòng for
				check=i;
				break;
			}		
		}
		for(int i=check+1;i<str.length();i++){
			str[i]='0';
		}
		//nếu là câu hình cuối cùng thì in ra cấu hình đầu tiên nếu không phải thì in ra cấu hình vừa tạo thành
		if(check==-1){
			for(int i=0;i<str.length();i++){
				cout<<"0";
			}
			cout<<endl;
		}else{
			for(int i=0;i<str.length();i++){
				cout<<str[i];
			}
			cout<<endl;
		}
	}
return 0;
}

