# include <bits/stdc++.h>
using namespace std;
struct person
{
    int father;
    int time;
};
int main(){
    int n;
    cin >> n;
    vector<person> persons(n+1);
    persons[1].father = 1;
    for(int i =2; i <= n; i++){
        int f;
        cin >> persons[i].father;
    }
    for(int i = 1; i <= n; i++){
        cin >> persons[i].time;
    }
    
}