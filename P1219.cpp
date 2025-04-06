#include <bits/stdc++.h>
using namespace std;
vector<int> a(15,0);
vector<int> lie(15,0);
vector<int> flagplus(15,0); // 斜线正方向,x+y
vector<int> flagminus(15,0); // 斜线负方向,x-y
int n;
int check(int x,int y);
void find(int x);
int flag = 0;
int main(){
    cin>>n;
    find(1); //从第一行开始放置皇后
    cout << flag << endl; //输出总解数

}
void find(int x){
    for(int i=1;i<=n;i++){
        if(check(x,i)){
            a[x] = i; //放置皇后
            lie[x] = i; //记录列
            flagplus[x] = x+i; //记录斜线正方向
            flagminus[x] = x-i; //记录斜线负方向
            if(x==n) {
                flag++;
                if(flag<=3){
                    for(int j=1;j<=n;j++){
                        cout<<a[j]<<" ";
                    }
                    cout<<endl;
                }
            }
            else find(x+1); //递归放置下一个皇后
        }
    }
}
int check(int x,int y){
    //判断第x行的第y列是否可以放置皇后
    if(x==1) return 1;
    for(int i=1;i<x;i++){
        if(lie[i]==y) return 0;
        //判断同一列
        if(flagplus[i]==x+y) return 0;
        //判断同一斜线
        if(flagminus[i]==x-y) return 0;
        //判断同一斜线
    }
    return 1;
}
