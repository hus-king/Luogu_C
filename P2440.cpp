#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> tree;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.push_back(x);
    }
    sort(tree.begin(), tree.end()); //从小到大排序
    int l = 1, r = tree[n-1];
    int mid;
    while(r >= l){
        mid = (l + r) / 2;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += tree[i] / mid;
        }
        if(sum >= k){ //切的段数够了,mid要大一点
            l = mid + 1;
        }
        else{ //切的段数不够了,mid要小一点
            r = mid - 1;
        }
    }
    cout << r << endl;
}