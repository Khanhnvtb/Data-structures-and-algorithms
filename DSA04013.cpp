//
// Created by khanh on 08/04/2021.
/*
Có N con kanguru trong vườn thú, con thứ i có chiều cao bằng A[i]. Con kanguru có chiều cao X có thể chứa được
một con có chiều cao bằng Y trong túi của nó nếu như X >= 2*Y.Một con đã chứa một con kanguru rồi, thì không
thể nhảy vào túi một con kanguru khác.Bầy Kanguru rất thích chơi trốn tìm, vì vậy chúng thường xuyên nhảy vào
túi của nhau. Các bạn hãy tính toán xem trong trường hợp tối ưu, số con kanguru nhìn thấy trong vườn thú ít
nhất bằng bao nhiêu?
Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên N (1 ≤ N ≤ 100 000).
Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 100 000).
Output:
Với mỗi test, in ra đáp án trên một dòng.
Input                         Output
2

8
2 5 7 6 9 8 4 2               5

8
9 1 6 2 6 5 8 3               5
*/
#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        long a[n];
        for(long i=0;i<n;i++){
            cin>>a[i];
        }
        //sắp xếp lại mảng a
        sort(a,a+n);
        //khởi tại vị trí bên phải là vị cuối cùng, vị trí bên trái là vị trí giữa và biến đêm số cặp bằng 0
        long r=n-1,l=n/2-1,count=0;
        //vòng lặp luôn đúng
        while(1){
            //thoả mãn điều kiện thì tăng số cặp lên 1 sau đó giảm vị trí phải và trái đi 1
            if(a[r]>=2*a[l]){
                count++;
                r--;
                l--;
            }else{
                //không thoả mãn thì giảm vị trí bên trái đi 1
                l--;
            }
            // nếu phần tử phải hoặc trái vượt quá giá trị tối thiểu thì dừng vòng lặp
            if(l==-1 || r==n/2-1){
                break;
            }
        }
        //in ra kết quả
        cout<<n-count<<"\n";
    }
    return 0;
}

