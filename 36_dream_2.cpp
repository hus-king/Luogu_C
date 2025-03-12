#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a;
    vector<int> b;
    vector<int> d(n+1,0);
    vector<int> c(n+1,0);
    for(int i=0;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    b.push_back(0);
    d[0] = 0 - a[0];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        b.push_back(x);
        d[i] = d[i-1] - a[i] + b[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> temp = d;
        for(int j=i;j<=n;j++){
            temp[j] -= b[i];
        }
        int min = 0;
        for(int j=1;j<=n;j++){
            if (temp[j] < min) min = temp[j];
        }
        c[i] = -min;
    }
    for(int i=1;i<=n;i++){
        cout<<c[i]<<" ";
    }
}