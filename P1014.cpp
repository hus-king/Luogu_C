#include <iostream>
using namespace std;
int calculate(int n);
int find(int x);
int main(){
    int n;
    cin>>n;
    int sum = find(n);
    int x,y,index;
    index = n - calculate(sum) + 1;
    if(sum%2==0){
        y = index;
        x = sum - index + 1;
    }
    else{
        x = index;
        y = sum - index + 1;
    }
    // cout<<"x = "<<x<<endl;
    // cout<<"y = "<<y<<endl;
    cout<<y<<"/"<<x;
    return 0;
}
int calculate(int n){
    int temp = n*(n-1);
    temp = temp / 2;
    temp = temp + 1;
    return temp;
}
int find(int x){
    int n = 2;
    while(x>=calculate(n)){
        n++;
    }
    return n-1;
}