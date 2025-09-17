#include <bits/stdc++.h>
using namespace std;
struct action{
    int x;
    int y;
    int z;

    action(int x, int y, int z) : x(x), y(y), z(z) {}
};

int main(){
    int n,p;
    cin >> n >> p;
    vector<int> a(n+1,0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<action> actions;
    for(int i = 1; i <= p; i++){
        int x,y,z;
        cin >> x >> y >> z;
        actions.emplace_back(x,y,z);
        //第x个到第y个学生每人增加z分
    }
    vector<int> minus(n+1,0);
    minus[1] = a[1];
    for(int i = 2; i <= n; i++){
        minus[i] = a[i] - a[i-1];
    }
    for(auto i:actions){
        minus[i.x] += i.z;
        if(i.y + 1 <= n){
            minus[i.y + 1] -= i.z;
        }
    }
    int min = INT_MAX;
    int temp = 0;
    for(int i = 1; i <= n; i++){
        temp += minus[i];
        if(temp < min){
            min = temp;
        }
    }
    cout << min << endl;
}