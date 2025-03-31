#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n, a[100005], d[270000], b[270000]; 
// n:数组长度 a:原数组 d:线段树数组 b:懒标记数组

//build:建树 update:更新 getsum:查询
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

void update(ll l,ll r,ll c,ll s,ll t,ll p){  // l:区间左端点 r:区间右端点 c:增加的值 s:修改的区间左端点 t:修改的区间右端点 p:节点标号
    if(l<=s && t<=r){
        d[p]+=(t-s+1)*c;
        b[p]+=c;
        return;
    }
    ll m = s + (t-s)/2;
    if(b[p]){
        d[p*2]+=(m-s+1)*b[p];
        d[p*2+1]+=(t-m)*b[p];
        b[p*2]+=b[p];
        b[p*2+1]+=b[p];
        b[p]=0;
    }
    if(l<=m) update(l,r,c,s,m,p*2);
    if(r>m) update(l,r,c,m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
}

ll getsum(ll l,ll r,ll s,ll t,ll p){ // l:区间左端点 r:区间右端点 s:查询的区间左端点 t:查询的区间右端点 p:节点标号  
    if(l<=s && t<=r) return d[p];
    ll m = s + (t-s)/2;
    if(b[p]){
        d[p*2]+=(m-s+1)*b[p];
        d[p*2+1]+=(t-m)*b[p];
        b[p*2]+=b[p];
        b[p*2+1]+=b[p];
        b[p]=0;
    }
    ll sum=0;
    if(l<=m) sum+=getsum(l,r,s,m,p*2);
    if(r>m) sum+=getsum(l,r,m+1,t,p*2+1);
    return sum;
}
int main(){
    ll q,i1,i2,i3,i4;
    cin>>n>>q;
    for(ll i=1;i<=n;i++) cin>>a[i];
    build(1,n,1);
    while(q--){
        cin>>i1>>i2>>i3;
        if(i1==2){
            cout<<getsum(i2,i3,1,n,1)<<endl;
        }else{
            cin>>i4;
            update(i2,i3,i4,1,n,1);
        }
    }
    return 0;
}