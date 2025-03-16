#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

// 并查集相关
int fa[MAXN]; // 并查集数组，用于快速找到未处理的节点

// 路径压缩的查找函数
int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]); // 路径压缩优化
    return fa[x];
}

int main() {
    int n;
    cin >> n;
    int a[n+1], k[n+1], dp[n+1]; // 输入数据数组和DP数组

    // 读取输入数据
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = -1; // 初始化DP为-1（表示未到达）
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    // 预处理：计算每个位置j跳跃后的实际目标位置
    int pos[n+1]; // pos[j] = j - a[j]
    for (int j = 1; j <= n; j++) {
        pos[j] = j - a[j];
    }

    // 初始化并查集（每个位置指向自己）
    for (int j = 1; j <= n+1; j++) {
        fa[j] = j;
    }

    // BFS初始化
    queue<int> q;
    dp[1] = 0;    // 起点步数为0
    q.push(1);    // 从起点开始搜索

    while (!q.empty()) {
        int i = q.front(); // 当前处理的位置
        q.pop();

        // 确定跳跃范围[i+1, i+k[i]]
        int start = i + 1;
        int end = i + k[i];
        if (end > n) end = n; // 防止越界

        if (start > end) continue; // 无效范围直接跳过

        // 使用并查集快速遍历可到达的节点
        int j = find(start); // 找到第一个未处理的节点
        while (j <= end) {
            int p = pos[j]; // 计算实际目标位置

            // 如果目标位置未到达过
            if (dp[p] == -1) {
                dp[p] = dp[i] + 1; // 更新步数
                q.push(p);         // 加入队列继续搜索
            }

            // 将当前节点标记为已处理（指向下一个位置）
            fa[j] = find(j + 1);
            // 继续查找下一个未处理的节点
            j = find(j);
        }
    }

    cout << dp[n]; // 输出到达终点的最小步数
    return 0;
}