#include <bits/stdc++.h>
using namespace std;

const int MAXN = 350; // 修改这里！

vector<vector<int>> my_map(MAXN, vector<int>(MAXN, -1));
vector<vector<int>> dist(MAXN, vector<int>(MAXN, INT_MAX));

vector<int> dx = {-1, 1, 0, 0, 0};
vector<int> dy = {0, 0, -1, 1, 0};
vector<int> step_x = {-1, 1, 0, 0};
vector<int> step_y = {0, 0, -1, 1};

int final_t = -1;

struct node{
    int x, y, t;
};

void bfs(){
    queue<node> beth;
    beth.push({0,0,0});
    if(my_map[0][0] == -1){
        final_t = 0;
        return;
    }
    if(my_map[0][0] == 0){
        final_t = -1;
        return;
    }
    dist[0][0] = 0;
    while(!beth.empty()){
        node now = beth.front();
        beth.pop();
        for(int i = 0; i < 4; i++){
            int tx = now.x + step_x[i];
            int ty = now.y + step_y[i];
            // 修改边界判断
            if(tx >= 0 && ty >= 0 && tx < MAXN && ty < MAXN){
                if(my_map[tx][ty] == -1){ // 安全区
                    final_t = now.t + 1;
                    return;
                }
                else if(my_map[tx][ty] > now.t + 1 && dist[tx][ty] > now.t + 1){
                    dist[tx][ty] = now.t + 1;
                    beth.push({tx, ty, now.t + 1});
                }
            }
        }
    }
}

int main(){
    int M;
    cin >> M;

    for(int i = 0; i < M; i++){
        int x,y,t;
        cin >> x >> y >> t;
        for(int j = 0; j <= 4; j ++){
            int tx = x + dx[j];
            int ty = y + dy[j];
            // 修改：加上 MAXN 限制
            if(tx >= 0 && ty >= 0 && tx < MAXN && ty < MAXN){
                if(my_map[tx][ty] == -1) 
                    my_map[tx][ty] = t;
                else 
                    my_map[tx][ty] = min(my_map[tx][ty], t);
            }
        }
    }

    bfs();
    cout << final_t << endl;
    return 0;
}