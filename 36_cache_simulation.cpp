#include <bits/stdc++.h>
using namespace std;
int n,N;
int calculate(int k){
    int result = k/n;
    result = result % N;
    return result;
}
int main(){
   int q;
   cin>>n>>N>>q;
   int cache[N][n][3] = {-1};
   for(int i=0;i<N;i++){
        for(int j=0;j<n;j++){
            cache[i][j][0] = -1;
            cache[i][j][1] = 0;
            cache[i][j][2] = 0;
        }
   }
   int key[N] = {0};
   vector<int> o(q);
   vector<int> a(q);
   for(int i=0;i<q;i++){
      int oo,aa;
      cin>>oo>>aa;
      o[i] = oo;
      a[i] = aa;
   }
   for(int i=0;i<q;i++){//处理第i个请求
        //第一步：判断是否命中
        int judge = 0;
        int index = calculate(a[i]);//index为第index个块(0~N-1)
        int j = 0;
        for(j=0;j<n;j++){
            if(cache[index][j][0] == a[i]){
                judge = 1;
                break;
            }
        }
        //如果命中，直接读写a[i]
        if(judge == 1){
            if(o[i]) cache[index][j][1] = o[i];//0为读，1为写
            cache[index][j][2] = key[index]++;
        }
        //如果未命中，需要读写
        else{
            //先判断有无空行
            int empty = 0;
            for(j=0;j<n;j++){
                if(cache[index][j][0] == -1){
                    empty = 1;
                    break;
                }
            }
            //如果有空行，直接读写
            if(empty == 1){
                cache[index][j][0] = a[i];
                cache[index][j][1] = o[i];
                cache[index][j][2] = key[index]++;
                cout<<0<<" "<<a[i]<<endl;
            }
            //如果没有空行，需要替换
            else{
                //寻找key值最小的行进行替换
                int min = 2147483647;
                int min_index = -1;
                for(j=0;j<n;j++){
                    if(cache[index][j][2] < min){
                        min = cache[index][j][2];
                        min_index = j;
                    }
                }
                //再判断该处有没有写入过数据
                if(cache[index][min_index][1] == 0){  //没有写入过数据,直接替换
                    cache[index][min_index][0] = a[i];
                    if(o[i]) cache[index][min_index][1] = o[i];
                    cache[index][min_index][2] = key[index]++;
                    cout<<0<<" "<<a[i]<<endl;
                }
                else{ //写入过数据，需要先读出数据，再写入数据
                    cout <<1<<" "<<cache[index][min_index][0]<<endl;
                    cache[index][min_index][0] = a[i];
                    if(o[i]) cache[index][min_index][1] = o[i];
                    cache[index][min_index][2] = key[index]++;
                    cout<<0<<" "<<a[i]<<endl;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<3;j++){
        //         cout<<cache[index][i][j]<<" "; 
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // cout<<endl;
   }
}
/*
4 8 6
1 0
1 1
1 2
1 3
0 1
0 32
*/