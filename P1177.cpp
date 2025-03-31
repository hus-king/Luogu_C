#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long a[100010];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}