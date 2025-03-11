#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t,m;
    cin>>t>>m;
    vector<vector<int>> v;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }
    vector<vector<int>> dp(m+1,vector<int>(t+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=t;j++){
            if(j>=v[i-1][0]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i-1][0]]+v[i-1][1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

}