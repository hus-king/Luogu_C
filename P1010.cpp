/*任何一个正整数都可以用 2 的幂次方表示。137 可表示为 2(2(2)+2+2(0))+2(2+2(0))+2(0)。
 1315 最后可表示为 2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)。*/
#include <iostream>
#include <cmath>
using namespace std;
string calculate(int n);
int find(int n);
string output;
int main(){
    int n;
    cin>>n;
    cout<<calculate(n);
    return 0;
}
string calculate(int n){
    if (n==1) return "2(0)";
    if (n==2) return "2";
    int temp = pow(2,find(n));
    if (n==temp) {
        if(n==2) return "2";
        else return "2("+calculate(find(n))+")";
    }
    else{
        if(temp==2) return "2+"+calculate(n-2);
        else return "2("+calculate(find(n))+")+"+calculate(n-temp);
    }
    return output;
}
int find(int n){
    int temp = 1;
    int out = 0;
    while(temp *2 <= n){
        temp*=2;
        out++;
    }
    return out;
}