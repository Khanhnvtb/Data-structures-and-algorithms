//
// Created by KhanhNVTB on 11/04/2021.
//
/*
Cho mảng các số nguyên A[] gồm N phần tử. Hãy chia mảng số nguyên A[] thành K tập con khác rỗng sao cho tổng các
phần tử của mỗi tập con đều bằng nhau. Mỗi phần tử thuộc tập con xuất hiện duy nhất một lần trong tất cả các tập
con. Ví dụ với A[] = {2, 1, 4, 5, 6}, K =3 ta có kết quả {2, 4}, {1, 5}, {6}.
Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và K; dòng tiếp theo
đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, K, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N, K≤20, 0≤A[i]≤100.
Output:
Đưa ra 1 nếu có thể chia tập con thành K tập thỏa mãn yêu cầu bài toán, ngược lại đưa ra 0.

Input                                  Output
2

5 3
2 1 4 5 6                              1

5 3
2 1 5 5 6                              0
*/
#include<bits/stdc++.h>
using namespace std;
int n,k,sum,a[20];
//khai báo mảng đánh dấu
bool used[100];
int check;
void Try(int s,int cnt){
    //nếu đã chia được thì dừng lại
    if(check==1){
        return;
    }
    for(int i=0;i<n;i++){
        //nếu chưa sử dụng thì tăng tổng của mảng hiện tại lên và đánh dấu là đã sử dụng
        if(used[i]==false){
            s+=a[i];
            used[i]=true;
            //nếu tồng mảng con bằng sum thì tăng số cặp lớn hơn thì dừng lại còn nhỏ hơn thì thử tiếp
            if(s==sum){
                cnt++;
                /*
                nếu đã đủ cặp thì cập nhật kết quả đã đúng còn chưa thì thử tiếp với tổng mảng con bằng 0 và số cặp
                hiện tại
                */
                if(cnt==k){
                    check=1;
                    return;
                }else {
                    Try(0, cnt);
                }
            }else if(s>sum){
                return;
            }else{
                Try(s,cnt);
            }
            //trả lại tổng mảng con sau khi sử dụng a[i]
            s-=a[i];
        }
        //gán lại phần tử i chưa sử dụng
        used[i]=false;
    }
}
main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        sum=0;
        check=0;
        //nhập vào các phần tử của mảng và tính tổng chung sao đó gán tất cả vị trí đều chưa sử dụng
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            used[i]=false;
        }
        //nếu tổng không chia hết cho k thì in 0 luôn còn nếu chia hết thì tiếp tục thử
        if(sum%k!=0){
            cout<<"0"<<"\n";
        }else {
            //gán tổng bằng tổng của mỗi mảng con cần tìm
            sum/=k;
            //thử với tổng của mỗi mảng bằng 0 và số mảng bằng 0
            Try(0, 0);
            //in ra kết quả
            if(check==0){
                cout<<"0"<<"\n";
            }else{
                cout<<"1"<<"\n";
            }
        }
    }
    return 0;
}
