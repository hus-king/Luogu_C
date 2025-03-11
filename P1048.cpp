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
    int dp[1010]={0};
    for(int i=0;i<m;i++){
        for(int j=t;j>=time[i];j--){
            dp[j]=max(dp[j],dp[j-time[i]]+value[i]);
        }
    }
    cout<<dp[t];
}