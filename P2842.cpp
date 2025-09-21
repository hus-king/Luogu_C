#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18; // 足够大的“无穷大”

int main() {
    long long n, w;
    cin >> n >> w;

    vector<long long> a(n + 1);        // 硬币面值，1-indexed
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // ✅ 动态分配 f[0..w]，避免越界风险
    vector<long long> f(w + 1, INF);   // 初始化所有 f[0..w] = INF
    f[0] = 0;                          // 凑出金额 0 需要 0 枚硬币

    // 完全背包：每种硬币无限使用
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= w; j++) {
            f[j] = min(f[j], f[j - a[i]] + 1);
        }
    }

    // 输出结果
    if (f[w] == INF) {
        cout << -1 << endl; // 无法凑出
    } else {
        cout << f[w] << endl;
    }

    return 0;
}