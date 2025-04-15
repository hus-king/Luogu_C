### 允许 $ k $ 次失配的字符串匹配

问题：给定长为 $ n $ 的源串 $ s $，以及长度为 $ m $ 的模式串 $ p $，要求查找源串中有多少子串与模式串匹配。$ s' $ 与 $ s $ 匹配，当且仅当 $ s' $ 与 $ s $ 长度相同，且最多有 $ k $ 个位置字符不同。其中 $ 1 \leq n, m \leq 10^6 $，$ 0 \leq k \leq 5 $。

这道题无法使用 KMP 解决，但是可以通过哈希 + 二分来解决。

枚举所有可能匹配的子串，假设现在枚举的子串为 $ s' $，通过哈希 + 二分可以快速找到 $ s' $ 与 $ p $ 第一个不同的位置。之后将 $ s' $ 与 $ p $ 在这个失配位置及之前的部分删除掉，继续查找下一个失配位置。这样的过程最多发生 $ k $ 次。

总的时间复杂度为 $ O(m + kn \log_2 m) $。



### 问题重述
给定一个长度为 \( n \) 的源串 \( s \) 和一个长度为 \( m \) 的模式串 \( p \)，要求找出源串中有多少个子串与模式串匹配。这里的匹配定义为：子串 \( s' \) 与 \( p \) 长度相同，且最多有 \( k \) 个位置的字符不同。其中 \( 1 \leq n, m \leq 10^6 \)，\( 0 \leq k \leq 5 \)。

### 解决思路
由于 \( k \) 的值较小（最多为 5），我们可以利用哈希和二分的方法来高效地解决这个问题。具体步骤如下：

1. **预处理哈希**：计算源串 \( s \) 和模式串 \( p \) 的前缀哈希值，以便快速比较任意子串的哈希值。
2. **枚举所有可能的子串**：源串 \( s \) 中所有长度为 \( m \) 的子串共有 \( n - m + 1 \) 个。
3. **检查每个子串与模式串的匹配**：
   • 使用哈希和二分的方法快速找到子串与模式串的第一个不同的位置。
   • 跳过这个不同的位置，继续在剩余的字符串中寻找下一个不同的位置。
   • 重复上述过程，直到找到 \( k + 1 \) 个不同位置（此时可以提前终止，因为已经不满足匹配条件）或者比较完整个字符串。
4. **统计匹配的子串数量**：如果子串与模式串的不同位置数不超过 \( k \)，则计数。

### 哈希方法
为了快速比较子串的哈希值，我们可以使用**滚动哈希**（如多项式滚动哈希）。具体来说：
• 选择一个基数 \( base \) 和一个模数 \( mod \)。
• 计算 \( s \) 和 \( p \) 的前缀哈希：
  • \( hash_s[i] = (hash_s[i-1] \cdot base + s[i]) \mod mod \)
  • \( hash_p[i] = (hash_p[i-1] \cdot base + p[i]) \mod mod \)
• 为了计算子串 \( s[l..r] \) 的哈希值：
  • \( hash = (hash_s[r] - hash_s[l-1] \cdot pow_base[r-l+1]) \mod mod \)
  • 其中 \( pow_base[i] = base^i \mod mod \)。

### 二分查找失配位置
对于两个字符串 \( a \) 和 \( b \)，如果要找到第一个不同的位置，可以使用二分：
1. 初始化 \( low = 0 \)，\( high = m - 1 \)。
2. 在 \( low \leq high \) 时：
   • \( mid = (low + high) / 2 \)。
   • 如果 \( a[0..mid] \) 和 \( b[0..mid] \) 的哈希值相同，则第一个不同位置在 \( mid + 1 \) 之后，更新 \( low = mid + 1 \)。
   • 否则，第一个不同位置在 \( mid \) 或之前，更新 \( high = mid - 1 \)。
3. 返回 \( low \)（即第一个不同的位置）。

### 时间复杂度
• 预处理哈希：\( O(n + m) \)。
• 枚举所有子串：\( O(n) \)。
• 检查每个子串：
  • 每次二分查找失配位置：\( O(\log m) \)。
  • 最多进行 \( k \) 次二分查找：\( O(k \log m) \)。
• 总时间复杂度：\( O(n + m + n \cdot k \log m) = O(n k \log m) \)（因为 \( n \) 和 \( m \) 同阶）。

### 代码实现
以下是 C++ 的实现代码，包含详细的中文注释：

```cpp
#include <iostream>
#include <string>
#include <vector>
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
```

### 代码解释
1. **预处理哈希**：
   • `pow_base[i]` 存储 \( BASE^i \mod MOD \)。
   • `hash_s` 和 `hash_p` 分别存储源串和模式串的前缀哈希值。
2. **哈希计算函数**：
   • `get_hash_s` 和 `get_hash_p` 分别计算源串和模式串子串的哈希值。
3. **匹配检查函数 `is_match`**：
   • 使用二分查找快速定位子串和模式串的第一个不同位置。
   • 如果不同位置数超过 \( k \)，则返回 `false`；否则返回 `true`。
4. **主函数**：
   • 读取输入并处理边界情况（如模式串比源串长）。
   • 枚举所有可能的子串，统计满足条件的子串数量。

这种方法利用了哈希和二分的高效性，能够在较大的数据规模下快速解决问题。