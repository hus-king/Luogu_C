#include <bits/stdc++.h>
using namespace std;
int check(string s1,string s2);
void find(int x);
string s[21];
string output = "";
string maxoutput = "";
int minustr = 0;
int n;
int key[21];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    cin>>s[0];
    for(int i=0;i<=n;i++){
        key[i] = 0;
    }
    output = s[0];
    find(0);
    // cout << maxoutput << endl;
    cout << maxoutput.length() << endl;
}
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
            minustr = i;
            break;
        }
    }
    return key;
}
void find(int x){
    // string temp = output;
    // output = minustr;
    // output += s[x];
    if(output.length() > maxoutput.length()){
        maxoutput = output;
    }
    for(int i=1;i<=n;i++){
        if(key[i] <= 1 && check(s[x],s[i]) == 1){
            key[i] ++;
            string temp = output;
            output += s[i].substr(minustr,s[i].length()-minustr);
            // cout << output << endl;
            find(i);
            output = temp;
            key[i] --;
        }
    }
    // key[x] --;
    // output = temp;
    return;
}
    