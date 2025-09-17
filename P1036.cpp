#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> x(21);
vector<int> small_primes;

void init_primes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            small_primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

bool IsPrime(int x) {
    if (x < 2) return false;
    for (int p : small_primes) {
        if (p * p > x) break;
        if (x % p == 0) return false;
    }
    return true;
}
int now_index = 0;
int now_sum = 0;
int now_num = 0;
int result = 0;
void dfs(){
    if(now_num == k){
        if(IsPrime(now_sum)) result++;
        return;
    }
    if(k - now_num > n - now_index) return;//剪枝
    //选取now_index
    if(now_index == n) return;
    now_sum += x[now_index];
    now_num++;
    now_index++;
    dfs();
    now_index--;
    now_sum -= x[now_index];
    now_num--;
    //不选取now_index
    now_index++;
    dfs();
    now_index--;
    return;
}
int main(){
    init_primes(10000);  // 因为最大 x 是 1e8，√x 最大 10000
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        cin >> x[i];
    }
    dfs();
    cout << result << endl;
    return 0;
}