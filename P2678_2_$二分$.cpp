#include <bits/stdc++.h>
using namespace std;
int L,M,N;
vector<int> rock(50004); //岩石位置
int check(int mid); //函数声明
int main(){
    cin >> L >> N >> M;
    //起点到终点的距离，起点和终点之间的岩石数，以及组委会至多移走的岩石数
    rock[0] = 0; //起点
    rock[N + 1] = L; //终点
    for(int i = 1; i <= N; i++){
        cin >> rock[i]; //输入岩石位置
    }
    int left = 1, right = L; //二分查找的左右边界
    int mid;
    while(left <= right){
        mid = (left + right) / 2; //取中间值
        if(check(mid) <= M){ //如果移除的岩石数小于等于组委会移走的岩石数,说明mid可以变大
            left = mid + 1; //缩小左边界
        }else{//如果移除的岩石数大于组委会移走的岩石数,说明mid可以变小
            right = mid - 1; //缩小右边界
        }
    }
    cout << right << endl; //输出结果
    return 0;
}
int check(int mid){
    vector<int> rocks = rock; //复制岩石位置
    int result = 0;
    for (int i = 0; i <= N; i++){
        if (rocks[i + 1] - rocks[i] < mid){ //距离比mid小，说明要移除后者
            result++;
            rocks[i+1] = rocks[i];
        }
    }
    return result; //返回移除的岩石数
}