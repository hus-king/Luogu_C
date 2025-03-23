#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll b[n]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll length=n;
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i] == a[i+1]){
            b[i] = 1;
            length--;
        }
    }
    cout<<length<<endl;
    for(int i=0;i<n;i++){
        if(b[i] == 0){
            cout<<a[i]<<" ";
        }
    }
}