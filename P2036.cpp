#include<bits/stdc++.h>
using namespace std;
int n;
struct food{
    int s;
    int b;
};
int best;
int now_s=1;
int now_b=0;
int now_num=0;
int now_index=1;
food foods[11];
void dfs(){
    if(now_num > 0){
        best = min(best, abs(now_s - now_b));
    }
    //选取now_index
    if(now_index > n) return;
    now_s *= foods[now_index].s;
    now_b += foods[now_index].b;
    now_num++;
    now_index++;
    dfs();
    now_s /= foods[now_index - 1].s;
    now_b -= foods[now_index - 1].b;
    now_num--;
    now_index--;
    //不选取now_index
    now_index++;
    dfs();
    now_index--;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>foods[i].s>>foods[i].b;
    }
    best = abs(foods[1].s - foods[1].b);
    dfs();
    cout<<best<<endl;
}