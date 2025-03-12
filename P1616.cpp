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
    long long dp[11000000]={0};
    for(int i = 1; i <= m; i++){
        for(int j = time[i-1]; j <= t; j++){
            dp[j] = max(dp[j],dp[j-time[i-1]]+value[i-1]);
        }
    }
    cout<<dp[t];
}