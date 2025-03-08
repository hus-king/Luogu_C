/*
棋盘上 A 点有一个过河卒，需要走到目标 B 点。卒行走的规则：可以向下、或者向右。同时在棋盘上 C 点有一个对方的马，
该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。
棋盘用坐标表示，A 点 (0,0)、B 点 (n,m)，同样马的位置坐标是需要给出的。
现在要求你计算出卒从 A 点能够到达 B 点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。
*/

// #include<iostream>
// using namespace std;
// int find();
// int chess[30][30]={0};
// int n,m,x,y;
// int output=0;
// int nx=0,ny=0;
// int main(){
//     cin>>n>>m>>x>>y;
//     chess[x][y]=-1;
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=m;j++){
//             if((abs(i-x)+abs(j-y)==3)&&(j!=y)&&(i!=x)) chess[i][j]=-1;
//         }
//     }
//     // for(int i=0;i<=n;i++){
//     //     for(int j=0;j<=m;j++){
//     //         cout<<chess[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
//     find();
//     cout<<output;
// }
// int find(){
//     if(chess[nx][ny]==-1) return 0;
//     if(nx==n&&ny==m){
//         output++;
//         return 0;
//     }
//     if(nx<n){
//         nx++;
//         find();
//         nx--;
//     }
//     if(ny<m){
//         ny++;
//         find();
//         ny--;
//     }
//     return 0;
// }
#include<iostream>
using namespace std;

int chess[30][30] = {0};
long long dp[30][30] = {0};
int n, m, x, y;

int main() {
    cin >> n >> m >> x >> y;
    chess[x][y] = -1;

    // 标记马的控制范围
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            chess[nx][ny] = -1;
        }
    }

    // 初始化dp数组
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (chess[i][j] == -1) {
                dp[i][j] = 0;
            } else {
                if (i > 0) dp[i][j] += dp[i-1][j];
                if (j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }

    cout << dp[n][m];
    return 0;
}