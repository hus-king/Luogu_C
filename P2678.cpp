#include<bits/stdc++.h>
using namespace std;
struct stone{
    int length;
    int i;
    stone(int length,int i):length(length),i(i){} //构造函数
};
struct cmp{ //自定义比较函数
    bool operator()(const stone &a,const stone &b){ //重载小于号
        return a.length > b.length;
    }
};
int main(){
    int L,n,m;
    //起点到终点的距离，起点和终点之间的岩石数，至多移走的岩石数
    cin>>L>>n>>m;
    vector<int> rock(n+2); //岩石位置
    rock[0] = 0; //起点
    rock[n+1] = L; //终点
    int result = 0; //结果
    for(int i=1;i<=n;i++){
        cin>>rock[i]; //输入岩石位置
    }
    vector<int> length(n+1); //岩石之间的距离
    for(int i=0;i<=n;i++){
        length[i] = rock[i+1] - rock[i]; //岩石之间的距离
    }
    while(m--){
        priority_queue<stone,vector<stone>,cmp> pq;
        for(int i=0;i<=n;i++){
            pq.push(stone(length[i],i)); //将岩石之间的距离和下标加入优先队列
        }
        stone temp = pq.top();
        result = temp.length;
        int index = temp.i; //下标
        if(index == 0) index =0;
        else if(index == n) index = n-1;
        else if(length[index-1] < length[index+1]) index = index - 1;
        length[index] = length[index] + length[index+1]; //将岩石之间的距离相加
        for(int i=index+1;i<=n-1;i++){
            length[i] = length[i+1]; //将后面的岩石之间的距离前移
        }
        n--; //岩石数减一
    }
    priority_queue<int,vector<int>,greater<int>> pq2;
    for(int i=0;i<=n;i++){
        pq2.push(length[i]); //将岩石之间的距离加入优先队列
    }
    result = pq2.top(); //取出最小的岩石之间的距离
    cout<<result<<endl; //输出结果
}