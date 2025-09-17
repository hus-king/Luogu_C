#include <bits/stdc++.h>
using namespace std;
struct work{
    int now;
    int sum;
    int best;
    int index;
    vector<int> time;
};
vector<work> works(4);

void find_best(work &x, int y);
int main(){
    for(int i = 0; i < 4; i++){
        cin >> works[i].index;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < works[i].index; j++){
            int t;
            cin >> t;
            works[i].time.push_back(t);
            works[i].sum += t;
        }
        works[i].best = works[i].sum;
        works[i].now = 0;
    }
    int ans = 0;
    for(int i = 0; i < 4; i++){
        find_best(works[i],0);
        ans += works[i].best;
    }
    cout << ans << endl;
    return 0;
}
void find_best(work &x, int y){
    if(x.now >= x.sum - x.now){
        x.best = min(x.best, x.now);
        return;
    }
    if(y == x.index) return;
    find_best(x,y + 1);//不选取y
    x.now += x.time[y];
    find_best(x,y + 1);//选取y
    x.now -= x.time[y];
    return;
}
/*
1 1 1 3
0
0
0
10 5 5
*/