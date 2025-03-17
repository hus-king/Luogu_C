#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int num[n+1];
    int sum[n+1];
    sum[0]=0;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        num[i]=s[i-1]-'0';
        sum[i]=sum[i-1]+num[i];
    }
    for(int i=0;i<m;i++){
        int op,l,r;
        cin>>op>>l>>r;
        if(op){
            int temp;
            temp = sum[r] - sum[l-1];
        }
        else{
            int index = r - l + 1;
            int change = index - (sum[r] - sum[l-1]);
        }
    }
}