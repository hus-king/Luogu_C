#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t,m;
    cin>>t>>m;
    vector<int> time;
    vector<int> value;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        time.push_back(a);
        value.push_back(b);
    }
    int dp[110][1010]={0};
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= t; j++){
            if(j < time[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-time[i-1]]+value[i-1]);
        }
    }
    cout<<dp[m][t];
}