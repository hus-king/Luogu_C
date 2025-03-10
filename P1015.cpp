#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> int2vector(int n);
vector<int> add(vector<int> a,int n);
unsigned int reverseHexBits(unsigned int num);
int main(){
    int n;
    cin>>n;
    if(n==16){
        unsigned int m;
        cin >> hex >> m;
        cout << hex << m;
        int flag =0, key = 0;
        for(int i = 1; i <= 30; i++){
            key ++;
            unsigned int temp = reverseHexBits(m);
            unsigned int temp2 = m + temp;
            if(temp2 == reverseHexBits(temp2)){
                cout << key << endl;
                flag = 1;
                break;
            }
            m = temp2;
        }
        if(flag == 0){
            cout << "Impossible!" << endl;
        }
    }
    else{
        int m;
        cin>>m;
        vector<int> a = int2vector(m);
        int flag = 0, key = 0;
        for(int i=1;i<=30;i++){
            key++;
            vector<int> temp = add(a,m);
            vector<int> temp2 = temp;
            reverse(temp.begin(),temp.end());
            if(temp2==temp){
                cout<<key<<endl;
                flag = 1;
                break;
            }
            a = temp2;
        }
        if(flag==0){
            cout<<"Impossible!"<<endl;
        }
    }
}
vector<int> int2vector(int n){
    vector<int> result;
    while(n){
        result.push_back(n%10);
        n/=10;
    }
    return result;
}
vector<int> add(vector<int> a,int n){
    vector<int> b = a;
    reverse(b.begin(),b.end());
    vector<int> result;
    int carry = 0;
    for(int i=0;i<b.size()||i<a.size();i++){
        int tempa = i<a.size()?a[i]:0;
        int tempb = i<b.size()?b[i]:0;
        int temp = tempa+tempb+carry;
        result.push_back(temp%n);
        carry = temp/n;
    }
    if(carry) result.push_back(carry);
    return result;
}
unsigned int reverseHexBits(unsigned int num) {
    unsigned int reversed = 0;
    const int bits = sizeof(num) * 8; // 获取总位数（如32位）
    for (int i = 0; i < bits; i += 4) {
        reversed <<= 4;          // 左移4位腾出空间
        reversed |= (num >> i) & 0xF; // 提取当前半字节并组合
    }
    return reversed;
}