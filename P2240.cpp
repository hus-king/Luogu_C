#include <bits/stdc++.h>
using namespace std;
struct coin{
    int m;
    int v;
    float p;
};
bool compare(coin a,coin b){
    return a.p > b.p;
}
int main(){
    vector<coin> coins(100); 
    float sum = 0;
    int N,T;
    cin>>N>>T;
    for(int i=0;i<N;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        coins[i].m = temp1;
        coins[i].v = temp2;
        coins[i].p = (float)temp2/(float)temp1;
    }
    sort(coins.begin(),coins.begin()+N,compare);
    for(auto x:coins){
        if(T>=x.m){
            sum += (float)x.v;
            T -= x.m;
        }
        else{
            sum += T * x.p;
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<sum;
}