#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N,M;
vector<int> num(500000);
int check(ll mid); //函数声明
int main(){
    cin >> N >> M; 
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    int max = 0;
    ll numsum = 0;
    for(int i = 0; i < N; i++){
        max = max > num[i] ? max : num[i];
        numsum += num[i];
    }
    // for(int i = max; i < numsum; i++){
    //     cout << i << " " << check(i) << endl;
    // }    
    ll left = max, right = numsum; //二分查找的左右边界
    ll mid;
    //check随着mid的增大而减小，要求mid的最小值
    while(left <= right){
        mid = (left + right) / 2; //取中间值
        if(check(mid) <= M){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    cout << left << endl; //输出结果
}
int check(ll mid){
    vector<int> nums = num;
    int result = 0;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        sum += nums[i];
        if(sum > mid){
            result++;
            sum = nums[i];
        }
    }
    return result+1;
}