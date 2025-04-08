#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b,c;
    //c=a+b
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    for(int i = 0;i < a.size() || i < b.size();i++){
        int A = i<a.size() ? a[i]-'0' : 0;
        int B = i<b.size() ? b[i]-'0' : 0;
        int sum = A + B + carry;
        carry = sum / 10;
        c.push_back(sum % 10 + '0');
    }
    if(carry > 0){
        c.push_back(carry + '0');
    }
    reverse(c.begin(),c.end());
    cout << c << endl;
}