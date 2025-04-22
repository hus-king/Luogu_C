#include <bits/stdc++.h>
using namespace std;
vector<int> sign(500003); //路标位置
int L,N,K; //公路的长度，原有路标的数量，以及最多可增设的路标数量。
int check(int mid); //函数声明
int main(){
    cin >> L >> N >> K;
    sign[0] = 0; //起点
    sign[N+1] = L; //终点
    for(int i=1;i<=N;i++){
        cin>>sign[i]; //输入路标位置
    }
    // for(int i = 1; i<=L ;i++){
    //     cout << i << " ";
    //     cout << check(i)<<endl;
    // }
    int left = 1, right = L; //二分查找的左右边界
    int mid;
    while(left <= right){
        mid = (left + right) / 2; //取中间值
        if(check(mid) <= K){ //如果增设的路标数小于等于组委会增设的路标数,说明mid可以变大
            right = mid - 1;
        }else{//如果增设的路标数大于组委会增设的路标数,说明mid可以变小
            left = mid + 1; //缩小右边界
        }
    }
    cout << left << endl; //输出结果
}
int check(int mid){
    vector<int> signs = sign;
    int result = 0;
    for(int i=0;i<=N;i++){
        if(signs[i+1]-signs[i]>mid){
            result++;
            signs[i] = signs[i] + mid;
            i--;
        }
    }
    return result; 
}