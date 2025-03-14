#include <bits/stdc++.h>
using namespace std;

struct CacheLine {
    long long tag;    // 存储地址
    int dirty;        // 脏位标记
    long long lru;    // LRU计数器
};

int n, N;

int calculate(long long k) {
    long long block = k / n;
    return (block % N + N) % N; // 确保非负索引
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> N >> q;

    vector<vector<CacheLine>> cache(N, vector<CacheLine>(n));
    vector<long long> key(N, 0);

    // 初始化缓存，全部置为无效
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < n; ++j) {
            cache[i][j].tag = -1;
            cache[i][j].dirty = 0;
            cache[i][j].lru = 0;
        }
    }

    vector<int> ops(q);
    vector<long long> addrs(q);
    for (int i = 0; i < q; ++i) {
        cin >> ops[i] >> addrs[i];
    }

    for (int i = 0; i < q; ++i) {
        int op = ops[i];
        long long addr = addrs[i];
        int index = calculate(addr);

        // 检查是否命中
        bool hit = false;
        int hit_pos = -1;
        for (int j = 0; j < n; ++j) {
            if (cache[index][j].tag == addr) {
                hit = true;
                hit_pos = j;
                break;
            }
        }

        if (hit) {
            // 命中：更新脏位和LRU
            if (op == 1) {
                cache[index][hit_pos].dirty = 1;
            }
            cache[index][hit_pos].lru = key[index]++;
        } else {
            // 未命中：寻找空行或替换
            int replace_pos = -1;
            bool has_empty = false;
            for (int j = 0; j < n; ++j) {
                if (cache[index][j].tag == -1) {
                    replace_pos = j;
                    has_empty = true;
                    break;
                }
            }

            if (!has_empty) {
                // 寻找LRU最小的行
                long long min_lru = cache[index][0].lru;
                replace_pos = 0;
                for (int j = 1; j < n; ++j) {
                    if (cache[index][j].lru < min_lru) {
                        min_lru = cache[index][j].lru;
                        replace_pos = j;
                    }
                }

                // 脏行需要写回
                if (cache[index][replace_pos].dirty == 1) {
                    cout << "1 " << cache[index][replace_pos].tag << '\n';
                }
            }

            // 载入新数据
            cout << "0 " << addr << '\n';
            cache[index][replace_pos].tag = addr;
            cache[index][replace_pos].dirty = (op == 1) ? 1 : 0;
            cache[index][replace_pos].lru = key[index]++;
        }
    }

    return 0;
}
