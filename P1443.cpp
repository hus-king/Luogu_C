#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
// 马的8个移动方向
vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
vector<vector<int>> chess(402, vector<int>(402, -1));

void bfs() {
    queue<pair<int, int>> q;
    q.push({x, y});
    chess[x][y] = 0;  // 起点步数为0
    
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int cx = current.first;
        int cy = current.second;
        int current_step = chess[cx][cy];
        
        // 尝试8个方向
        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            // 检查边界和是否未访问
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && chess[nx][ny] == -1) {
                chess[nx][ny] = current_step + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m >> x >> y;
    bfs();
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << chess[i][j];
            if (j < m) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
// # include<bits/stdc++.h>
// using namespace std;
// int n,m,x,y;
// int step = 0;
// vector<int> x_chess = {-2, -1, 1, 2, -2, -1, 1, 2};
// vector<int> y_chess = {-1, -2, -2, -1, 1, 2, 2, 1};
// vector<vector<int>> chess(402, vector<int>(402,-1));
// void horse(int a, int b){
//     chess[a][b] = step;
//     for(int i = 0; i < 8; i++){
//         int tx = a + x_chess[i];
//         int ty = b + y_chess[i];
//         if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && (chess[tx][ty] == -1 || chess[tx][ty] > step + 1)){
//             step++;
//             horse(tx,ty);
//             step--;
//         }
//     }
//     return;
// }
// int main(){
//     cin >> n >> m >> x >> y;//n×m 的棋盘
//     horse(x,y);
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             cout << chess[i][j] << " ";
//         }
//         cout << endl;
//     }
// }