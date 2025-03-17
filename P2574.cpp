#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int num[n+1];
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        num[i]=s[i-1]-'0';
    }
    for(int i=0;i<m;i++){
        int op,l,r;
        cin>>op>>l>>r;
        if(op){
            int sum=0;
            for(int j=l;j<=r;j++){
                sum+=num[j];
            }
            cout<<sum<<endl;
        }
        else{
            for(int j=l;j<=r;j++){
                num[j]=1-num[j];
            }
        }
    }
}