#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MAXN = 1e6 + 10;
const ull BASE = 131; // 哈希基数，通常选择一个质数
const ull MOD = 1e9 + 7; // 哈希模数

ull pow_base[MAXN]; // pow_base[i] = BASE^i % MOD
ull hash_s[MAXN];   // 源串 s 的前缀哈希
ull hash_p[MAXN];   // 模式串 p 的前缀哈希

// 预处理哈希
void init_hash(const string& s, const string& p) {
    pow_base[0] = 1;
    for (int i = 1; i <= max(s.size(), p.size()); ++i) {
        pow_base[i] = (pow_base[i-1] * BASE) % MOD;
    }

    hash_s[0] = 0;
    for (int i = 1; i <= s.size(); ++i) {
        hash_s[i] = (hash_s[i-1] * BASE + s[i-1]) % MOD;
    }

    hash_p[0] = 0;
    for (int i = 1; i <= p.size(); ++i) {
        hash_p[i] = (hash_p[i-1] * BASE + p[i-1]) % MOD;
    }
}

// 计算 s[l..r] 的哈希值（1-based）
ull get_hash_s(int l, int r) {
    return (hash_s[r] - hash_s[l-1] * pow_base[r - l + 1] % MOD + MOD) % MOD;
}

// 计算 p[l..r] 的哈希值（1-based）
ull get_hash_p(int l, int r) {
    return (hash_p[r] - hash_p[l-1] * pow_base[r - l + 1] % MOD + MOD) % MOD;
}

// 检查 s 的子串 s[start..start+m-1] 是否与 p 匹配
bool is_match(const string& s, const string& p, int start, int k) {
    int n = s.size(), m = p.size();
    int s_l = start + 1, s_r = start + m; // 转换为 1-based
    int p_l = 1, p_r = m;

    int mismatch = 0;
    while (p_l <= p_r) {
        // 找到第一个不同的位置
        int low = p_l, high = p_r, pos = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            ull s_hash = get_hash_s(s_l + p_l - 1, s_l + mid - 1);
            ull p_hash = get_hash_p(p_l, mid);
            if (s_hash == p_hash) {
                low = mid + 1;
            } else {
                pos = mid;
                high = mid - 1;
            }
        }
        if (pos == -1) break; // 剩余部分完全匹配
        mismatch++;
        if (mismatch > k) return false;
        p_l = pos + 1; // 跳过这个不同的位置
    }
    return mismatch <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ### 3.7.2 允许 $ k $ 次失配的字符串匹配

    问题：给定长为 $ n $ 的源串 $ s $，以及长度为 $ m $ 的模式串 $ p $，要求查找源串中有多少子串与模式串匹配。$ s' $ 与 $ s $ 匹配，当且仅当 $ s' $ 与 $ s $ 长度相同，且最多有 $ k $ 个位置字符不同。其中 $ 1 \leq n, m \leq 10^6 $，$ 0 \leq k \leq 5 $。
    
    这道题无法使用 KMP 解决，但是可以通过哈希 + 二分来解决。
    
    枚举所有可能匹配的子串，假设现在枚举的子串为 $ s' $，通过哈希 + 二分可以快速找到 $ s' $ 与 $ p $ 第一个不同的位置。之后将 $ s' $ 与 $ p $ 在这个失配位置及之前的部分删除掉，继续查找下一个失配位置。这样的过程最多发生 $ k $ 次。
    
    总的时间复杂度为 $ O(m + kn \log_2 m) $。### 3.7.2 允许 $ k $ 次失配的字符串匹配

问题：给定长为 $ n $ 的源串 $ s $，以及长度为 $ m $ 的模式串 $ p $，要求查找源串中有多少子串与模式串匹配。$ s' $ 与 $ s $ 匹配，当且仅当 $ s' $ 与 $ s $ 长度相同，且最多有 $ k $ 个位置字符不同。其中 $ 1 \leq n, m \leq 10^6 $，$ 0 \leq k \leq 5 $。

这道题无法使用 KMP 解决，但是可以通过哈希 + 二分来解决。

枚举所有可能匹配的子串，假设现在枚举的子串为 $ s' $，通过哈希 + 二分可以快速找到 $ s' $ 与 $ p $ 第一个不同的位置。之后将 $ s' $ 与 $ p $ 在这个失配位置及之前的部分删除掉，继续查找下一个失配位置。这样的过程最多发生 $ k $ 次。

总的时间复杂度为 $ O(m + kn \log_2 m) $。### 3.7.2 允许 $ k $ 次失配的字符串匹配

问题：给定长为 $ n $ 的源串 $ s $，以及长度为 $ m $ 的模式串 $ p $，要求查找源串中有多少子串与模式串匹配。$ s' $ 与 $ s $ 匹配，当且仅当 $ s' $ 与 $ s $ 长度相同，且最多有 $ k $ 个位置字符不同。其中 $ 1 \leq n, m \leq 10^6 $，$ 0 \leq k \leq 5 $。

这道题无法使用 KMP 解决，但是可以通过哈希 + 二分来解决。

枚举所有可能匹配的子串，假设现在枚举的子串为 $ s' $，通过哈希 + 二分可以快速找到 $ s' $ 与 $ p $ 第一个不同的位置。之后将 $ s' $ 与 $ p $ 在这个失配位置及之前的部分删除掉，继续查找下一个失配位置。这样的过程最多发生 $ k $ 次。

总的时间复杂度为 $ O(m + kn \log_2 m) $。### 3.7.2 允许 $ k $ 次失配的字符串匹配

问题：给定长为 $ n $ 的源串 $ s $，以及长度为 $ m $ 的模式串 $ p $，要求查找源串中有多少子串与模式串匹配。$ s' $ 与 $ s $ 匹配，当且仅当 $ s' $ 与 $ s $ 长度相同，且最多有 $ k $ 个位置字符不同。其中 $ 1 \leq n, m \leq 10^6 $，$ 0 \leq k \leq 5 $。

这道题无法使用 KMP 解决，但是可以通过哈希 + 二分来解决。

枚举所有可能匹配的子串，假设现在枚举的子串为 $ s' $，通过哈希 + 二分可以快速找到 $ s' $ 与 $ p $ 第一个不同的位置。之后将 $ s' $ 与 $ p $ 在这个失配位置及之前的部分删除掉，继续查找下一个失配位置。这样的过程最多发生 $ k $ 次。

总的时间复杂度为 $ O(m + kn \log_2 m) $。### 3.7.2 允许 $ k $ 次失配的字符串匹配

问题：给定长为 $ n $ 的源串 $ s $，以及长度为 $ m $ 的模式串 $ p $，要求查找源串中有多少子串与模式串匹配。$ s' $ 与 $ s $ 匹配，当且仅当 $ s' $ 与 $ s $ 长度相同，且最多有 $ k $ 个位置字符不同。其中 $ 1 \leq n, m \leq 10^6 $，$ 0 \leq k \leq 5 $。

这道题无法使用 KMP 解决，但是可以通过哈希 + 二分来解决。

枚举所有可能匹配的子串，假设现在枚举的子串为 $ s' $，通过哈希 + 二分可以快速找到 $ s' $ 与 $ p $ 第一个不同的位置。之后将 $ s' $ 与 $ p $ 在这个失配位置及之前的部分删除掉，继续查找下一个失配位置。这样的过程最多发生 $ k $ 次。

总的时间复杂度为 $ O(m + kn \log_2 m) $。
    string s, p;
    int k;
    cin >> s >> p >> k;

    int n = s.size(), m = p.size();
    if (m > n) {
        cout << 0 << "\n";
        return 0;
    }

    init_hash(s, p);

    int res = 0;
    for (int i = 0; i <= n - m; ++i) {
        if (is_match(s, p, i, k)) {
            res++;
        }
    }
    cout << res << "\n";

    return 0;
}