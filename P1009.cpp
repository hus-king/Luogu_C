#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<vector<int>> number;
vector<int> add(vector<int> a,vector<int> b);
vector <int> output;
void calculate(int n);
vector<int> mul(vector<int> a,int b);
int main(){
    int n;
    cin>>n;
    calculate(n);
    for(int i=0;i<n;i++){
        output = add(output,number[i]);
    }
    for(int i=output.size()-1;i>=0;i--){
        cout<<output[i];
    }
    return 0;
}
void calculate(int n){
    number.push_back({1});
    for(int i=2;i<=n;i++){
        vector<int> temp = mul(number.back(),i);
        number.push_back(temp);
    }
}
vector<int> mul(vector<int> a,int b){
    vector <int> result;
    int carry = 0;
    for (int i=0;i<a.size();i++){
        int temp = a[i]*b+carry;
        result.push_back(temp%10);
        carry = temp/10;
    }
    while(carry){
        result.push_back(carry%10);
        carry/=10;
    }
    return result;
}
vector<int> add(vector<int> a,vector<int> b){
    vector<int> result;
    int carry = 0;
    for(int i=0;i<a.size()||i<b.size();i++){
        int tempa = i<a.size()?a[i]:0;
        int tempb = i<b.size()?b[i]:0;
        int temp = tempa+tempb+carry;
        result.push_back(temp%10);
        carry = temp/10;
    }
    if(carry) result.push_back(carry);
    return result;
}