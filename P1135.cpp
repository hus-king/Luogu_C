#include <bits/stdc++.h>
using namespace std;
vector<int> k(201,0);
vector<int> flag(201,0);
vector<int> step(201,0);
struct Floor{
    int index;
    int step;

    Floor(int i, int s) : index(i), step(s) {}
};
struct cmp{
    bool operator()(Floor a, Floor b){
        return a.step > b.step;
    }
};
priority_queue<Floor, vector<Floor>, cmp> pq;
int main(){
    int N,A,B;
    cin >> N >> A >> B;
    for(int i = 1; i <= N; i++){
        cin >> k[i];flag[i] = 0;step[i] = -1;
    }
    flag[A] = 1;step[A] = 0;
    pq.push(Floor(A,0));
    while(!pq.empty()){
        Floor temp = pq.top();
        pq.pop();
        if(temp.index + k[temp.index] <= N && flag[temp.index + k[temp.index]] == 0){
            flag[temp.index + k[temp.index]] = 1;
            step[temp.index + k[temp.index]] = temp.step + 1;
            pq.push(Floor(temp.index + k[temp.index], temp.step + 1));
        }
        if(temp.index - k[temp.index] >= 1 && flag[temp.index - k[temp.index]] == 0){
            flag[temp.index - k[temp.index]] = 1;
            step[temp.index - k[temp.index]] = temp.step + 1;
            pq.push(Floor(temp.index - k[temp.index], temp.step + 1));
        }
        if(flag[B] == 1) break;
    }
    cout << step[B] << endl;
    return 0;
}