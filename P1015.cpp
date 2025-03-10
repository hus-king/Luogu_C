#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string calculate(string a,int n);
int check(string a);
int main(){
    int n;
    string m;
    cin>>n>>m;
    int step = 1;
    int key = 0; 
    while(step <= 30){
        m = calculate(m,n);
        if(check(m)){
            cout<<"STEP="<<step<<endl;
            key = 1;
            break;
        }
        step++;
    }
    if(!key) cout<<"Impossible!"<<endl;
}
string calculate(string a,int n){
    string b = a;
    reverse(b.begin(),b.end());
    string reslut;
    int carry = 0;
    for(int i=0;i < a.size() || i < b.size();i++){
        int tempa,tempb;
        if (n==16){
            tempa = i < a.size() ? a[i] > '9' ? a[i] - 'A' + 10 : a[i] - '0' : 0;
            tempb = i < b.size() ? b[i] > '9' ? b[i] - 'A' + 10 : b[i] - '0' : 0;
        }
        else{
            tempa = i < a.size() ? a[i] - '0' : 0;
            tempb = i < b.size() ? b[i] - '0' : 0;
        }
        int temp = tempa + tempb + carry;
        char c;
        if(n == 16) c = temp % 16 > 9 ? temp % 16 - 10 + 'A' : temp % 16 + '0';
        else c = temp % n + '0';
        reslut.push_back(c);
        carry = temp / n;
    }
    if(carry) reslut.push_back(carry + '0');
    return reslut;
}
int check(string a){
    string b = a;
    reverse(b.begin(),b.end());
    if(a == b) return 1;
    else return 0;
}