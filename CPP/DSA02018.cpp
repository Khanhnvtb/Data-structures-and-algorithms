//
// Created by khanh on 10/04/2021.
//
/*Cho 5 số nguyên dương A, B, C, D, E. Bạn có thể hoán vị các phần tử cho nhau, hãy đặt các dấu biểu thức +, -, * sao
cho biểu thức sau đúng:
[[[A o(1) B] o(2) C] o(3) D] o(4) E = 23
Trong đó: o(1) … o(4) là các phép toán +, -, *.
Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 5 số nguyên dương A, B, C, D, E có giá trị không vượt quá 100.
Output: Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.
Input                                        Output
3

1 1 1 1 1                                    NO

1 2 3 4 5                                    YES

2 3 5 7 11                                   YES
*/
#include <bits/stdc++.h>
using namespace std;
int a[5];
int check;
int c[5];
//bắt đầu thử từ 0 với kết quả bằng A
void Try(int i, int res) {
    //nếu đã tìm ra trường hợp thoả mãn thì dừng
    if (check == 1) {
        return;
    }
    //vòng lặp 2 ứng với '+' 1 ứng với '-' và 0 ứng với '*'
    for (int j = 2; j >= 0; j--) {
        if (j == 2) {
            //kết quả được cọng lên
            res += c[i + 1];
            //khi đã duyệt đến E và kết quả bằng 23 thì gán biến kiểm tra bằng 1 chưa thử đến E thì thử tiếp
            if (i == 3 && res == 23) {
                check = 1;
            } else if (i < 3) {
                Try(i + 1, res);
            }
            //khi dùng xong trả lại kết quả trước đó
            res -= c[i + 1];
        } else if (j == 1) {
            //kết quả được trừ lên
            res -= c[i + 1];
            //khi đã duyệt đến E và kết quả bằng 23 thì gán biến kiểm tra bằng 1 chưa thử đến E thì thử tiếp
            if (i == 3 && res == 23) {
                check = 1;
            } else if (i < 3) {
                Try(i + 1, res);
            }
            //khi dùng xong trả lại kết quả trước đó
            res += c[i + 1];
        }else {
            //kết quả được nhân lên
            res *= c[i + 1];
            //khi đã duyệt đến E và kết quả bằng 23 thì gán biến kiểm tra bằng 1 chưa thử đến E thì thử tiếp
            if (i == 3 && res == 23) {
                check = 1;
            } else if (i < 3) {
                Try(i + 1, res);
            }
            //khi dùng xong trả lại kết quả trước đó
            res /= c[i + 1];
        }
    }
}
//hàm sinh các hoán vị của A B C D E
void hoanvi(int k,int b[]) {
    for (int i = 0; i <= 4; i++) {
        if (!b[a[i]]) {
            c[k] = a[i];
            b[a[i]] = 1;
            if (k == 4) {
                //khi sinh xong 1 hoán vị thì thử các phép toán
                Try(0, c[0]);
                //nếu đã có kết quả đúng rồi thì dừng lại
                if (check == 1) {
                    break;
                }
            }else
                hoanvi(k + 1,b);
            b[a[i]] = 0;
        }
    }
}
main(){
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<5;i++){
            cin>>a[i];
            c[i]=a[i];
        }
        check=0;
        int b[101]={false};
        hoanvi(0,b);
        if(check==1){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}
