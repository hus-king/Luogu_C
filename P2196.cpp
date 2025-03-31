#include <bits/stdc++.h>
using namespace std;
struct Node{
    int value = 0;  //节点的值
    string p;  //路径
};
int main(){
    int N;  // 地窖的个数
    cin >> N;
    vector<int> A(N+1);  // 地窖中地雷的个数
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    vector<vector<int>> path  (N+1,vector<int>(N+1));  // 地窖之间的路径
    for( int i=1;i<=N;i++){
        path[i][i] = 0;  // 地窖i到地窖i的路径为0
        for(int j=i+1;j<=N;j++){
            cin >> path[i][j];  // 地窖i到地窖j的路径(0或1)
        }
    }
    vector<Node> dp(N+1);  // dp数组，表示第i个地窖时挖到地雷的最大值
    for(int i=1;i<=N;i++){
        dp[i].value = A[i];  // 初始化dp数组，表示第i个地窖时挖到地雷的最大值
        dp[i].p = to_string(i);  // 初始化路径为i
    }
    int ans = A[1];  // 最终的答案
    int ans_index = 1;  // 最终的答案的下标
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(path[i][j] == 1){  // 如果地窖i和地窖j之间有路径
                // dp[j] = max(dp[j],dp[i]+A[j]);  // 更新dp[j]的值
                if(dp[j].value < dp[i].value + A[j]){
                    dp[j].value = dp[i].value + A[j];  // 更新dp[j]的值
                    dp[j].p = dp[i].p + " " + to_string(j);  // 更新路径为dp[i].p +" " + dp[j].p
                }
                if(dp[j].value > ans){  // 如果dp[j]的值大于当前的答案
                    ans = dp[j].value;
                    ans_index = j;  // 更新最终的答案的下标为j
                }
            }
            else{
                if(dp[j].value > ans){  // 如果dp[j]的值大于当前的答案
                    ans = dp[j].value;
                    ans_index = j;  // 更新最终的答案的下标为j
                }
            }
        }
    }
    cout << dp[ans_index].p << endl;  // 输出最终的答案的路径
    cout << ans << endl;  // 输出最终的答案
}