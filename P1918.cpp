#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> bottle(n);
    for(int i=0;i<n;i++) cin>>bottle[i];
    int Q;
    cin>>Q;
    vector<int> query(Q);
    for(int i=0;i<Q;i++) cin>>query[i];
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[bottle[i]] = i+1;
    }
    for(int i=0;i<Q;i++){
        if(mp.count(query[i])) cout<<mp[query[i]]<<endl;
        else cout<<0<<endl;
    }
    return 0;
}