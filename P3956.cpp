#include <bits/stdc++.h>
using namespace std;
struct dp{
    int coin;
    int magic = 1;
};
int main(){
    int m,n;
    cin >> m,n;
    vector<vector<int>> block(m + 1, vector<int>(m + 1, -1));
    for(int i = 1; i <= n; i++){
        int x,y,c;
        cin >> x >> y >> c;
        block[x][y] = c;
    }
}