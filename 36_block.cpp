#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n+1];//需要后退ai
    int k[n+1];//最多前进ki
    int dp[n+1]; // dp[i]表示到第i个位置的最小步数
    //1<=n<=10^5, 0<=a[i]<i, 1<=k[i]<=10^9
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = -1;
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
    }
    dp[1] = 0;
    for(int i=1;i<n;i++){
        if(dp[i]==-1) continue;
        for(int j=1;j<=k[i];j++){
            if(i+j == n+1) break;
            if(dp[i+j-a[i+j]]==-1) dp[i+j-a[i+j]] = dp[i] + 1;
            else dp[i+j-a[i+j]] = min(dp[i+j-a[i+j]],dp[i]+1);
        }
    }
    cout << dp[n];
}
/*
10
0 1 1 1 1 3 1 0 3 0
2 4 5 4 1 4 1 3 5 3
4
*/