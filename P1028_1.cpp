#include <iostream>
#include <vector>
using namespace std;
void find(int n);
vector<int> flag = {0};
vector<int> ans = {0};
int main(){
    int n;
    cin>>n;
    find(n);
    cout<<ans[n];
}
void find(int n){
    ans[n]++;
    if(n == 1){
        flag[n] = 1;
        return;
    }
    for(int i=1;i<=n/2;i++){
        if(flag[i] == 0){
            find(i);
            ans[n] += ans[i];
        }
        else{
            ans[n] += ans[i];
        }
    }
    flag[n] = 1;
    return;
}
