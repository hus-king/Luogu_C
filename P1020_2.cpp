#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a;
    int temp;
    while (cin >> temp) {
        a.push_back(temp);
    }
    int n = a.size();
    
    // 处理最长非递增子序列
    vector<int> dp1;
    for (int x : a) {
        // 使用upper_bound在非递增数组中找插入位置
        auto it = upper_bound(dp1.begin(), dp1.end(), x, greater<int>());
        if (it == dp1.end()) {
            dp1.push_back(x);
        } else {
            *it = x;
        }
    }
    int res1 = dp1.size();
    
    // 处理最长递增子序列
    vector<int> dp2;
    for (int x : a) {
        // 使用lower_bound在递增数组中找插入位置
        auto it = lower_bound(dp2.begin(), dp2.end(), x);
        if (it == dp2.end()) {
            dp2.push_back(x);
        } else {
            *it = x;
        }
    }
    int res2 = dp2.size();
    
    cout << res1 << endl << res2 << endl;
    return 0;
}