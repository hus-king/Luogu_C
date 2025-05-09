#include <bits/stdc++.h>
using namespace std;
struct block{
    int value;
    int group = -1;
};
int gruopindex = 1;
vector<int> groupindexs;
int a[4]={-1,0,0,1};
int b[4]={0,-1,1,0};
int main(){
    int N;
    cin >> N;
    vector<vector<block>> blocks(N+2, vector<block>(N+2));
    for(int i = 0; i <= N+1; i++){
        for(int j = 0; j <= N+1; j++){
            if(i == N+1 || j == N+1 || i == 0 || j == 0) blocks[i][j].value = -1;
            else cin >> blocks[i][j].value;
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(blocks[i][j].value == 0){
                if(blocks[i][j].group == -1){ // 这个点是一个新的组
                    int rootflag = -1;
                    for(int k = 0; k < 4; k++){
                        if(blocks[i+a[k]][j+b[k]].group != -1){
                            rootflag = k;
                            break;
                        }
                    }
                    if(rootflag == -1){
                        blocks[i][j].group = gruopindex;
                        gruopindex++;
                        groupindexs.push_back(blocks[i][j].group);
                    }
                    else{
                        blocks[i][j].group = blocks[i+a[rootflag]][j+b[rootflag]].group;
                    }
                }
                for(int k = 0; k < 4; k++){ //从这个点开始向四周扩展
                    if(blocks[i+a[k]][j+b[k]].value == 0){
                        blocks[i+a[k]][j+b[k]].group = blocks[i][j].group;
                    }
                    if(blocks[i+a[k]][j+b[k]].value == -1){ //与边界相连，不符合要求，从gruopindexs中删除
                        groupindexs.erase(
                            remove(groupindexs.begin(), groupindexs.end(), blocks[i][j].group),
                            groupindexs.end()
                        );
                    }
                }
            }
        }
    }
    for(int i = N; i >= 1; i--){
        for(int j = N; j >= 1; j--){
            if(blocks[i][j].value == 0){
                if(blocks[i][j].group == -1){ // 这个点是一个新的组
                    int rootflag = -1;
                    for(int k = 0; k < 4; k++){
                        if(blocks[i+a[k]][j+b[k]].group != -1){
                            rootflag = k;
                            break;
                        }
                    }
                    if(rootflag == -1){
                        blocks[i][j].group = gruopindex;
                        gruopindex++;
                        groupindexs.push_back(blocks[i][j].group);
                    }
                    else{
                        blocks[i][j].group = blocks[i+a[rootflag]][j+b[rootflag]].group;
                    }
                }
                for(int k = 0; k < 4; k++){ //从这个点开始向四周扩展
                    if(blocks[i+a[k]][j+b[k]].value == 0){
                        blocks[i+a[k]][j+b[k]].group = blocks[i][j].group;
                    }
                    if(blocks[i+a[k]][j+b[k]].value == -1){ //与边界相连，不符合要求，从gruopindexs中删除
                        groupindexs.erase(
                            remove(groupindexs.begin(), groupindexs.end(), blocks[i][j].group),
                            groupindexs.end()
                        );
                    }
                }
            }
        }
    }
    int final_index = groupindexs.back();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(blocks[i][j].value == 0 && blocks[i][j].group == final_index){
                blocks[i][j].value = 2;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << blocks[i][j].value << " ";
        }
        cout << endl;
    }
}