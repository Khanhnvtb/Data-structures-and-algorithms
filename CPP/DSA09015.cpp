//
// Created by khanh on 5/21/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, check, vs[1005];
vector <int> a[1005];
void bfs(int u) {
    queue <int> q;
    q.push(u);
    while (! q.empty()) {
        u = q.front();
        q.pop();
        int tmp;
        for (int i = 0; i < a[u].size(); i ++) {
            tmp = a[u][i];
            if (vs[tmp] == 1) {
                check = 1;
                return;
            } else if (vs[tmp] == 0) {
                q.push(tmp);
            }
            vs[tmp] = 2;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>v>>e;
        while(e--){
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
        }
        check=0;
        for(int i=1;i<=v;i++){
            memset(vs,0,sizeof(vs));
            vs[i] = 1;
            bfs(i);
            if(check) {
                break;
            }
        }
        if(check){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
        for(int i=1;i<=v;i++){
            a[i].clear();
        }
    }
    return 0;
}