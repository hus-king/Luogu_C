#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(2));
    a[0][0] = 1;
    a[0][1] = 1;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i][0] >> a[i][1];
        sum += a[i][1] - a[i][0];
    }
    vector<vector<int>> dp(n+1, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i = 1; i <= n; i++){
        dp[i][0] = min(dp[i-1][0] + abs(a[i][0] - a[i-1][1]), dp[i-1][1] + abs(a[i][0] - a[i-1][0]));
        dp[i][1] = min(dp[i-1][0] + abs(a[i][1] - a[i-1][1]), dp[i-1][1] + abs(a[i][1] - a[i-1][0]));
    }
    sum = sum + min(dp[n][0]+(n-a[n][1]), dp[n][1]+(n-a[n][0]));
    sum += n-1;
    cout << sum << endl;
}