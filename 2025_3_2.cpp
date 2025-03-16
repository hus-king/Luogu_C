#include <bits/stdc++.h>
using namespace std;
string convert10to16(string s);
int main(){
    string s;
    getline(cin,s);
    int n = s.size();
    for(int i = 0; i < n; i++){
        int j;
        if(s[i] == '{'){
            string convert;
            convert += s[i];
            for(j = i + 1; j < n; j++){
                if(s[j] != '}' && s[j] != ' '){
                    convert += s[j];
                }
                if(s[j] == '}'){
                    break;
                }
            }
            convert += '}';
            // cout << convert << endl;
            string result = convert10to16(convert);
            result = "0x" + result;
            // cout << result << endl;
            s.replace(i, j - i + 1, result);
            // cout << s << endl;
            n = s.size(); // 更新字符串长度
            i += result.size() - 1; // 更新索引位置
        }
    }
    cout << s << endl;
    return 0;
}
string convert10to16(string s){
    int n = s.size();
    int sum = 0;
    for(int i = 1; i < n-1; i++){
        sum = sum * 10 + s[i] - '0';
    }
    string result;
    while(sum){
        int temp = sum % 16;
        if(temp < 10){
            result += temp + '0';
        }else{
            result += temp - 10 + 'A';
        }
        sum /= 16;
    }
    reverse(result.begin(),result.end());
    return result;
}