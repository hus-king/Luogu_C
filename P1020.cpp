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
    int maxn=dp[l];
    for(int i = l-1; i >= 0; i--){
        for(int j = i+1; j < l; j++){
            if(a[i] >= a[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        if(dp[i] > maxn){
            maxn = dp[i];
        }
        maxdp[i] = max(maxdp[i+1], dp[i]);
    }
    cout << maxn << endl;
    vector<int> dpm(l+1, 1); // dpm[i]表示i之前的最长递增子序列的长度
    int maxm=dpm[1];
    for(int i = 1; i < l; i++){
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]){
                dpm[i] = max(dpm[i], dpm[j]+1);
            }
        }
        if(dpm[i] > maxm){
            maxm = dpm[i];
        }
    }
    cout << maxm << endl;
}