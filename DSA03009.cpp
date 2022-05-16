//
// Created by khanh on 09/04/2021.
//
/*Cho N công việc. Mỗi công việc được biểu diễn như một bộ 3 số nguyên dương <JobId, Deadline, Profit>, trong đó JobId
là mã của việc, Deadline là thời gian kết thúc của việc, Profit là lợi nhuận đem lại nếu hoàn thành việc đó đúng thời
gian. Thời gian để hoàn toàn mỗi công việc là 1 đơn vị thời gian. Hãy cho biết lợi nhuận lớn nhất có thể thực hiện các
việc với giả thiết mỗi việc được thực hiện đơn lẻ.
Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là số lượng Job N; phần thứ hai đưa vào
3×N số tương ứng với N job.
T, N, JobId, Deadline, Profit thỏa mãn ràng buộc:1≤T≤100;  1≤N≤1000; 1≤ JobId ≤1000; 1≤ Deadline ≤1000;1≤ Profit ≤1000.
Output:
Đưa số lượng công việc tương ứng và lợi nhuận lớn nhất có thể đạt được.
Input                                           Output
2
4

1 4 20                                          2 60
2 1 10
3 1 40
4 1 30

5

1 2 100                                         2 127
2 1 19
3 2 27
4 1 25
5 1 15
*/
#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--) {
        int a[1001];
        int b[1001];
        int n;
        cin >> n;
        //khai báo dealine tối đa và số công việc tối đa thực hiện được
        int max = 0, count = 0;
        for(int i=0;i<n;i++){
            int j;
            cin >> j >> a[i] >> b[i];
            //tìm dealine tối đa
            if(a[i]>max){
                max=a[i];
            }
        }
        //sắp xếp theo thứ tự số lợi nhuận đạt được
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(b[i]>b[j]){
                    swap(b[i],b[j]);
                    swap(a[i],a[j]);
                }
            }
        }
        long res = 0;
        //mảng kiểm tra thời gian đó đã làm công việc nào chưa
        bool used[1001] = {false};
        for (int i = n - 1; i >= 0; i--) {
            //nếu dealine tối đa còn lại nhỏ hơn 1 thì dừng vòng lặp
            if(max<=0) {
                break;
            }
            /*
            nếu dealine lớn hơn dealine tối đa thì kiểm tra nếu tại thời gian tối đa đã làm 1 công việc thì tiếp tục trừ
            đến khi có thời gian chưa làm
            nếu dealine nhỏ hơn dealine tối đa thì kiểm tra xem tại thời gian của dealine đã làm 1 công việc thì tiếp
            tục trừ đến khi có thời gian chưa làm
            */
            if (a[i] >= max ) {
                while(used[max]==true){
                    max--;
                }
                /*
                nếu dealine tối đa lớn hơn 0 thì ghi nhận công việc tăng lợi nhuận, đánh dấu thời gian đó đã được làm
                sau đó giảm dealine tối đa xuống 1 và tăng số công việc đã làm lên 1
                */
                if(max>0) {
                    res += b[i];
                    used[max] = true;
                    count++;
                    max--;
                }
            }else if (a[i] < max ) {
                int x=a[i];
                while(used[x]==true){
                    x--;
                }
                /*
                nếu dealine lớn hơn 0 thì ghi nhận công việc tăng lợi nhuận, đánh dấu thời gian đó đã được làm và tăng
                số công việc đã làm lên 1
                */
                if(x>0){
                    res+=b[i];
                    used[x]=true;
                    count++;
                }
            }
        }
        //in ra kết quả
        cout << count << " " << res << "\n";
    }
    return 0;
}
