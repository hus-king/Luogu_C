#include "bits/stdc++.h"
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(2 * n + 1), sum(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];  // 破环成链
    }

    // 前缀和：sum[i] = a[1] + ... + a[i]
    for (int i = 1; i < 2 * n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }

    // DP 表
    vector<vector<int>> mi(2 * n + 1, vector<int>(2 * n + 1, INT_MAX));
    vector<vector<int>> ma(2 * n + 1, vector<int>(2 * n + 1, 0));

    // 初始化：单堆合并代价为 0
    for (int i = 1; i < 2 * n; ++i) {
        mi[i][i] = ma[i][i] = 0;
    }

    // 区间 DP：len = 区间长度
    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l + len - 1 < 2 * n; ++l) {
            int r = l + len - 1;
            int total = sum[r] - sum[l - 1];  // 提前计算，避免重复
            for (int k = l; k < r; ++k) {
                mi[l][r] = min(mi[l][r], mi[l][k] + mi[k + 1][r] + total);
                ma[l][r] = max(ma[l][r], ma[l][k] + ma[k + 1][r] + total);
            }
        }
    }

    int ans_min = INT_MAX, ans_max = 0;
    for (int i = 1; i <= n; ++i) {
        ans_min = min(ans_min, mi[i][i + n - 1]);
        ans_max = max(ans_max, ma[i][i + n - 1]);
    }

    cout << ans_min << '\n' << ans_max << endl;
    return 0;
}