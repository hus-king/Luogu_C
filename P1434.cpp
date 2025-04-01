#include <bits/stdc++.h>
struct Node{
    int value = 0;  //已知最长路径
    int flag=0; //是否遍历到底
};
using namespace std;
#define find(valuenow,x,y) ((x>0)&&(x<=R)&&(y>0)&&(y<=C)&&(valuenow>a[x][y])) //判断是否越界
int calculatePath(int x,int y);
int R,C;   //行数和列数
vector<vector<int>> a(100+1,vector<int>(1000+1));  
vector<vector<Node>> dp(100+1,vector<Node>(100+1));
int main(){
    cin>>R>>C;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>a[i][j];  //输入二维数组
        }
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            dp[i][j].value = 1;  //初始化dp数组
            dp[i][j].flag = 0;  //初始化flag为0
        }
    }
    int ans = 1;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            ans = max(ans,calculatePath(i,j));  //更新最大值
        }
    }
    cout<<ans<<endl;  //输出最大值
}
int calculatePath(int x,int y){
    int tempmax = 1;  //当前值
    if(dp[x][y].flag == 1){  //如果已经遍历到底
        return dp[x][y].value;  //返回当前值
    }
    if(dp[x][y].flag == 0){  //如果没有遍历到底
        dp[x][y].flag = 1;  //标记为遍历到底
    }
    int valuenow = a[x][y];  //当前值
    int go[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};  //四个方向
    for(int i=0;i<4;i++){
        int x1 = x + go[i][0];  //下一个位置的x坐标
        int y1 = y + go[i][1];  //下一个位置的y坐标
        if(find(valuenow,x1,y1)){  //判断是否越界
            if(dp[x1][y1].flag == 0){  //如果没有遍历到底
                tempmax = max(tempmax,1+calculatePath(x1,y1));  //更新最大值
            }
            else{
                tempmax = max(tempmax,1+dp[x1][y1].value);  //更新最大值
            }
        }
    }
    dp[x][y].value = tempmax;  //更新dp数组
    return dp[x][y].value;  //返回最大值
}
