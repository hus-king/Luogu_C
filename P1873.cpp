#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll cal(int h,int tree);
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> tree;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        tree.push_back(x);
    }
    sort(tree.begin(), tree.end()); //从小到大排序

    // 1 2 3 4 5 6   100
    // l         mid       r
    int l = 0, r = tree[N-1];
    int mid;
    int flag = 0;
    while(r >= l){
        mid = (l + r) / 2;
        ll sum = 0;
        for(int i = 0; i < N; i++){
            sum += cal(mid, tree[i]);
        }
        if(sum > M){  //砍的太多了,mid要大一点
            l = mid + 1;
            flag = 0;
        }
        else if(sum < M){ //砍的太少了,mid要小一点
            r = mid - 1;
            flag = 1;
        }
        else{ //刚好砍到
            flag = 0;
            break;
        }
    }
    cout << mid - flag << endl;
}
ll cal(int h,int tree){
    ll ans = tree - h;
    if(ans < 0) return 0;
    return ans;
}