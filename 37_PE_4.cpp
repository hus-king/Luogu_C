#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    unordered_map<int, pair<ll, ll>> prev;

    for (int r = 0; r < n; ++r) {
        unordered_map<int, pair<ll, ll>> curr;
        int x = a[r];

        for (auto& [g_old, p] : prev) {
            ll sum_i_prev = p.first;
            ll cnt_prev = p.second;
            int g_new = gcd(g_old, x);
            curr[g_new].first += sum_i_prev;
            curr[g_new].second += cnt_prev;
        }

        ll j = r + 1;
        int g_new = x;
        curr[g_new].first += j;
        curr[g_new].second += 1;

        for (auto& [g, p] : curr) {
            ll sum_i = p.first;
            ans = (ans + g * j % MOD * sum_i % MOD) % MOD;
        }

        prev = move(curr);
    }

    cout << ans % MOD << endl;
    return 0;
}