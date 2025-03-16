#include <bits/stdc++.h>

using namespace std;
int check(string s);
int play(string s, int key);
int main(){
    string s;
    cin >> s;
    int Q;
    cin >> Q;
    int l[Q+1], r[Q+1];
    for(int i = 1; i <= Q; i++){
        cin >> l[i] >> r[i];
    }
    for(int i = 1; i <= Q; i++){
        string temp = s.substr(l[i]-1, r[i]-l[i]+1);
        // cout << temp << endl;
        int key = 0;
        key = play(temp, key);
        // cout << key << endl;
        if(key == 0){
            cout << "TSUH" << endl;
        }else if(key % 2 == 0){
            cout << "HUST" << endl;
        }else{
            cout << "TSUH" << endl;
        }
    }
}
int check(string s){
    string temp = s;
    reverse(temp.begin(),temp.end());
    if(temp == s){
        return 1;
    }else{
        return 0;
    }
} 
int play(string s, int key){
    if (check(s)) return key;
    key++;
    int key1 = key;
    int key2 = key;
    int n = s.size();
    string temp1 = s;
    temp1.pop_back();
    string temp2 = s;
    temp2.erase(temp2.begin());
    //对于此时来说最优解为所得key与此时keymod2不同余
    key1 = play(temp1, key1);
    key2 = play(temp2, key2);
    bool flag1 = key1 % 2 != key % 2;
    bool flag2 = key2 % 2 != key % 2;
    if(flag1) key = key1;
    else if(flag2) key = key2;
    else key = key1;
    return key;
}