#include <bits/stdc++.h>
using namespace std;
struct block{
    int value;
    int key1 = 0;
    int key2 = 0;
};
int main(){
    int N;
    cin >> N;
    vector<vector<block>> blocks(N+1, vector<block>(N+1));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> blocks[i][j].value;
        }
    }
    for(int i = 1; i <= N; i++){
        int strart = 1e6;
        int end = 0;
        for(int j = 1; j <= N; j++){ //横着走
            if(blocks[i][j].value == 1){
                strart = j;
                break;
            }
        }
        for(int j = N; j >= 1; j--){
            if(blocks[i][j].value == 1){
                end = j;
                break;
            }
        }
        for(int j = strart; j <= end; j++){
            blocks[i][j].key1 = 1;
        }
    }
    for(int j = 1; j <= N; j++){
        int strart = 1e6;
        int end = 0;
        for(int i = 1; i <= N; i++){ //竖着走
            if(blocks[i][j].value == 1){
                strart = i;
                break;
            }
        }
        for(int i = N; i >= 1; i--){
            if(blocks[i][j].value == 1){
                end = i;
                break;
            }
        }
        for(int i = strart; i <= end; i++){
            blocks[i][j].key2 = 1;
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(blocks[i][j].key1 == 1 && blocks[i][j].key2 == 1 && blocks[i][j].value == 0){
                blocks[i][j].value = 2;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(blocks[i][j].value == 0){
                int a[4] = {-1, 0, 0, 1};
                int b[4] = {0, -1, 1, 0};
                for(int k = 0; k < 4; k++){
                    int x = i + a[k];
                    int y = j + b[k];
                    if(x >= 1 && x <= N && y >= 1 && y <= N){
                        if(blocks[x][y].value == 2){
                            blocks[x][y].value = 0;
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << blocks[i][j].value << " ";
        }
        cout << endl;
    }
    return 0;
}