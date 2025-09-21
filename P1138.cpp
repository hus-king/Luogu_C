#include<bits/stdc++.h>
#include <set>
using namespace std;
int main(){
    int n,k;
    set<int> num;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        num.insert(t);
    }
    if(num.size()<k) cout<<"NO RESULT"<<endl;
    else{
        auto it=num.begin();
        advance(it,k-1);
        cout<<*it<<endl;
    }
}