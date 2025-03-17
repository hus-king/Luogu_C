//d[p] 表示从 s 到 t 的区间和
//对于 100% 的数据，保证 2≤n,m≤2×10^5,0≤op≤1，1≤l≤r≤n
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n, a[200005], d[800010], b[800010]; 
// n:数组长度 a:原数组 d:线段树数组 b:懒标记数组

void build(ll l,ll r,ll p){  // l:区间左端点 r:区间右端点 p:节点标号
    if(l==r){
        d[p]=a[l];
        return;
    }
    ll m = l + (r-l)/2;
    build(l,m,p*2);
    build(m+1,r,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
}

void update(ll l,ll r,ll s,ll t,ll p){
    if(l<=s && t<=r){
        d[p]=(t-s+1)-d[p];
        //将从s到t的区间取反
        b[p]+=1;
        return;
    }
    ll m = s + (t-s)/2;
    if(b[p]%2){
        //如果懒标记为奇数，说明需要取反
        d[p*2]=(m-s+1)-d[p*2];
        d[p*2+1]=(t-m)-d[p*2+1];
        b[p*2]+=1;
        b[p*2+1]+=1;
        b[p]=0;
    }
    if(l<=m) update(l,r,s,m,p*2);
    if(r>m) update(l,r,m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
}

ll getsum(ll l,ll r,ll s,ll t,ll p){ // l:区间左端点 r:区间右端点 s:查询的区间左端点 t:查询的区间右端点 p:节点标号  
    if(l<=s && t<=r) return d[p];
    ll m = s + (t-s)/2;
    if(b[p]%2){
        d[p*2]=(m-s+1)-d[p*2];
        d[p*2+1]=(t-m)-d[p*2+1];
        b[p*2]+=1;
        b[p*2+1]+=1;
        b[p]=0;
    }
    ll sum=0;
    if(l<=m) sum+=getsum(l,r,s,m,p*2);
    if(r>m) sum+=getsum(l,r,m+1,t,p*2+1);
    return sum;
}
int main(){
    ll q,i1,i2,i3;
    cin>>n>>q;
    string s;
    cin >> s;
    for(ll i=1;i<=n;i++){
        a[i] = s[i-1] - '0';
    }
    build(1,n,1);
    while(q--){
        cin>>i1>>i2>>i3;
        if(i1==1){
            cout<<getsum(i2,i3,1,n,1)<<endl;
        }else{
            update(i2,i3,1,n,1);
        }
    }
    return 0;
}