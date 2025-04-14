#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    // Sparse Table for GCD queries
    int k = log2(n) + 1;
    vector<vector<int>> st(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; ++i) {
        st[i][0] = a[i];
    }
    for (int j = 1; j <= k; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    
    auto query_gcd = [&](int l, int r) {
        int len = r - l + 1;
        int j = log2(len);
        return gcd(st[l][j], st[r - (1 << j) + 1][j]);
    };
    
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        int current_gcd = a[i];
        int left = i;
        while (left <= n) {
            int l = left, r = n;
            int best = left;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (query_gcd(i, mid) == current_gcd) {
                    best = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            long long sum_j = (long long)(best + left) * (best - left + 1) / 2 % MOD;
            res = (res + (long long)current_gcd * i % MOD * sum_j % MOD) % MOD;
            left = best + 1;
            if (left <= n) {
                current_gcd = query_gcd(i, left);
            }
        }
    }
    cout << res << '\n';
    
    return 0;
}