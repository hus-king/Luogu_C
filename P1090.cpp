#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    priority_queue<int, vector<int>, greater<int>> pq; // 小根堆
    int n;
    cin >> n;
    ll sum = 0;

    // 将所有元素加入优先队列
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    // 每次取出两个最小的元素合并，并将结果加入堆中
    while (pq.size() > 1) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        sum += x + y;
        pq.push(x + y);
    }

    cout << sum << endl;
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int main(){
//     vector<int> a;
//     int n;
//     cin >> n;
//     ll sum = 0;
//     for(int i = 0; i < n; i++){
//         int x;
//         cin >> x;
//         a.push_back(x);
//     }
//     for(int i = 0; i < n-1; i++){
//         sort(a.begin(), a.end(), greater<int>());
//         int x = a.back();
//         a.pop_back();
//         a.back() += x;
//         sum += a.back();      
//     }
//     cout << sum << endl;
//     return 0;
// }