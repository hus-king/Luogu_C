#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double a,b,c,d;
int times = 0;
double solv[4];
void solve(double n);
double calculate(double n);
int check(double n);
int main(){
    cin>>a>>b>>c>>d;
    for(int i=-100;i<100;i++){
        if(abs(calculate(i))<0.0001){
            solv[times++] = i;
        }
    }
    for(int i=-100;i<100;i++){
        if(times == 3) break;
        if(calculate(i)*calculate(i+1)<0) solve(i);
    }
    sort(solv,solv+times);
    for(int i=0;i<times;i++) printf("%.2f ",solv[i]);
}
double calculate(double n){
    double result = 0;
    result = a*pow(n,3)+b*pow(n,2)+c*n+d;
    return result;
}
void solve(double n){
    double min = 1e6;
    double ans = 0;
    double x = n;
    while (x <= n + 1)
    {
        if (abs(calculate(x)) <= min && check(x))
        {
            min = abs(calculate(x));
            ans = x;
        }
        x += 0.01;
    }
    solv[times++] = ans;
}
int check(double n){
    for(int i=0;i<times;i++){
        if(abs(n-solv[i])<1) return 0;
    }
    return 1;
}