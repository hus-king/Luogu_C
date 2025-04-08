#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N, C;
    cin >> N >> C;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // 从小到大排序
    ll key = 0;
    for (auto it = a.begin(); it != a.end(); ++it) {
        int temp = *it + C;
        // 寻找 a 中等于 temp 的数的个数
        auto it_lower = lower_bound(next(it), a.end(), temp);
        // it_lower 为第一个大于等于 temp 的数的下标
        auto it_upper = upper_bound(next(it), a.end(), temp);
        // it_upper 为第一个大于 temp 的数的下标
        ll count = it_upper - it_lower;
        key += count;
    }
    cout << key << endl;
}