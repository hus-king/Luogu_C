#include "bits/stdc++.h"
using namespace std;
struct bead {
    int start;
    int end;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<bead> beads(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> beads[i].start;
    }
    for (int i = 1; i <= n; ++i) {
        beads[i].end = beads[i % n + 1].start;
        beads[i + n] = beads[i];  // 破环成链
    }

    // DP 表
    vector<vector<int>> ma(2 * n + 1, vector<int>(2 * n + 1, 0));
    // 初始化：单个珠子能量值为 0
    for (int i = 1; i < 2 * n; ++i) {
        ma[i][i] = 0;
    }
    // 区间 DP：len = 区间长度
    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l + len - 1 < 2 * n; ++l) {
            int r = l + len - 1;
            for (int k = l; k < r; ++k) {
                int energy = beads[l].start * beads[k].end * beads[r].end;
                ma[l][r] = max(ma[l][r], ma[l][k] + ma[k + 1][r] + energy);
                //l-r = l-k + k+1-r + l.start * k.end * r.end
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, ma[i][i + n - 1]);
    }

    cout << ans << endl;
    return 0;
}