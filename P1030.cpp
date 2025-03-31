//前序：中 左 右
//中序：左 中 右
//后序：左 右 中
#include <bits/stdc++.h>
using namespace std;
int main(){
    string middle,back,front;
    cin>>middle>>back;
    int n = middle.size();
    for(int i=0;i<n;i++){
        int pos = back.find(middle[i]);
        front+=middle[i];
        front+=back.substr(0,pos);
        back = back.substr(pos+1);
    }
    cout<<front;
    return 0;
}