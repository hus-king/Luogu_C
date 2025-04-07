#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a;
    int temp;
    while(cin >> temp){
        a.push_back(temp);
    }
    int l = a.size();
    vector<int> dp(l+1, 1); // dp[i]表示i之后的最长递减子序列的长度
    vector<int> maxdp(l+1, 1);// maxdp[i]表示dp[i]到dp[l]的最大值 
    int maxn=dp[l];
    //i     j      l
    for(int i = l-1; i >= 0; i--){
        for(int j = i+1; j < l; j++){
            if(a[i] >= a[j]){
                dp[i] = max(dp[i], dp[j]+1);
                // if(dp[j] == maxdp[j]) break;
                if(dp[j]+1 > dp[i]){
                    if(dp[j] == maxdp[j]) break;
                }
            }
        }
        if(dp[i] > maxn){
            maxn = dp[i];
        }
        maxdp[i] = max(maxdp[i+1], dp[i]);
    }
    cout << maxn << endl;
    vector<int> dpm(l+1, 1); // dpm[i]表示i之前的最长递增子序列的长度
    vector<int> maxdpm(l+1, 1);// maxdpm[i]表示dpm[1]到dpm[i]的最大值
    //j     i      l
    int maxm=dpm[1];
    for(int i = 1; i < l; i++){
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]){
                dpm[i] = max(dpm[i], dpm[j]+1);
                // if(dpm[j] == maxdpm[j]) break;
                if(dpm[j]+1 > dpm[i]){
                    if(dpm[j] == maxdpm[j]) break;
                }
            }
        }
        if(dpm[i] > maxm){
            maxm = dpm[i];
        }
    }
    cout << maxm << endl;
}