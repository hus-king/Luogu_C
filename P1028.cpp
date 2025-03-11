# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int key = 0;
void find(int n);
int main(){
    int n;
    cin>>n;
    find(n);
    cout<<key;
}
void find(int n){
    key ++;
    if(n == 1){
        return;
    }
    for(int i=1;i<=n/2;i++){
        find(i);
    }
}
