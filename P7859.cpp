#include <bits/stdc++.h>
using namespace std;
vector<int> choose(21,0);
vector<vector<int>> check(21,vector<int>(21,0));
int output = 0;
int N,M;
void pizza(int x);
int main(){
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        int x,y;cin >> x >> y;
        check[min(x,y)][max(x,y)] = 1;
    }
    pizza(1);
    cout << output << endl;
    return 0;
}
void pizza (int x){
    if(x == N+1){
        output++;
        return;
    }
    pizza(x+1);
    int flag = 1;
    for(int i = 1; i < x; i++){
        if(choose[i] == 1 && check[i][x] == 1){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        choose[x] = 1;
        pizza(x+1);
        choose[x] = 0;
    }
}