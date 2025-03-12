#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a;
    vector<int> b;
    vector<int> d(n+1,0);
    vector<int> min(n+1,0);
    vector<int> bmin(n+1,0);
    //min[i] 为从0到i中d的最小值
    vector<int> c(n+1,0);
    for(int i=0;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    b.push_back(0);
    d[0] = 0 - a[0];
    min[0] = d[0];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        b.push_back(x);
        d[i] = d[i-1] - a[i] + b[i];
        if (d[i] < min[i-1]) min[i] = d[i];
        else min[i] = min[i-1];    
    }
    bmin[n] = d[n];
    for(int i=n-1;i>=1;i--){
        if(d[i] < bmin[i+1]) bmin[i] = d[i];
        else bmin[i] = bmin[i+1];
    }
    for(int i=1;i<=n;i++){
        if(min[i-1] < (bmin[i] - b[i])) c[i] = min[i-1];
        else c[i] = bmin[i] - b[i];
    }
    for(int i=1;i<=n;i++){
        cout<<-c[i]<<" ";
    }
}

/*
 0  1   2  3
-5 -5  -5 -5
 0  0 100  0
-5 -10 95 80
*/