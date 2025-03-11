# include <iostream>
using namespace std;
int value[1010] = {0};
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        //计算value[i]的值
        value[i]++;
        for(int j=1;j<=i/2;j++){
            value[i] += value[j];
        }
    }
    cout<<value[n];
}