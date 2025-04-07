#include <bits/stdc++.h>
using namespace std;
int check(string s1,string s2){
    //判断s1和s2能否接龙
    int len1 = s1.length();
    int len2 = s2.length();
    int key = 0;
    int flag = min(len1,len2);
    if(flag == 1) flag ++;
    for(int i=1;i<flag;i++){
        // i为研究子串的长度
        string check1 = s1.substr(len1-i,i);
        string check2 = s2.substr(0,i);
        // check1为s1的后i个字符，check2为s2的前i个字符
        if(check1 == check2){
            key = 1;
            break;
        }
    }
    return key;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<check(s1,s2)<<endl;
    return 0;
}