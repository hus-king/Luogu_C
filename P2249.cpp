//1 2 3 4 5 x lower_bound upper_bound
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int find(int x);
int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    // reverse(a.begin(), a.end()); // 不需要反转
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        cout << find(x) << " ";
    }
    return 0;
}
int find(int x){
    auto first = lower_bound(a.begin(), a.end(), x);
    auto last = upper_bound(a.begin(), a.end(), x);
    if (first == last) return -1;
    return first - a.begin() + 1;
}