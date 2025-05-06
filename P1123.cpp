#include <bits/stdc++.h>
using namespace std;
int maxsum = 0;
int a[8]={-1,0,1,-1,1,-1,0,1};
int b[8]={-1,-1,-1,0,0,1,1,1};
int N,M;
int sum = 0;
vector<vector<int>> number(9, vector<int>(9, -1));
vector<vector<int>> flag (9, vector<int>(9, 0));
void deep(int ii);
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                flag[i][j] = 0;
                cin >> number[i][j];
            }
        }
        sum = 0;
        deep(1);
        cout << maxsum <<endl;
        maxsum = 0;
    }
}
void deep(int ii){
    maxsum = max(sum,maxsum);
    for(int i = ii; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(flag[i][j] == 0){
                flag[i][j] = 1;
                int temp[8];
                for(int k = 0; k < 8; k++){
                    int x = i + a[k];
                    int y = j + b[k];
                    temp[k] = flag[x][y];
                    flag[x][y] = 1;
                }
                sum += number[i][j];
                deep(i);
                sum -= number[i][j];
                flag[i][j] = 0;
                for(int k = 0; k < 8; k++){
                    int x = i + a[k];
                    int y = j + b[k];
                    flag[x][y] = temp[k];
                }
            }
        }
    }
}