#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a;
    vector<int> b;
    vector<int> c(n+1,0);
    for(int i=0;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    b.push_back(0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    for(int i=1;i<=n;i++){
        int min = 0-a[0];
        int tempb = b[i];
        b[i]=0;
        int temp = min;
        for(int j=1;j<=n;j++){
            temp = temp - a[j] + b[j];
            if (temp < min) min = temp;
        }
        c[i] = -min;
        b[i] = tempb;
    }
    for(int i=1;i<=n;i++){
        cout<<c[i]<<" ";
    }
}