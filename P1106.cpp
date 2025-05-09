#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    k = n-k;
    int sum = 0;
    vector<int> num(n+1, 0);
    for(int i = 1; i <= n; i++){
        num[i] = s[i-1] - '0';
    }
    int start = 1;
    while(k--){
        int minnum = INT_MAX;
        int minindex = -1;
        for(int i = start; i <= n-k; i++){
            if(num[i] < minnum){
                minnum = num[i];
                minindex = i;
            }
        }
        start = minindex + 1;
        sum = sum * 10 + minnum;
    }
    cout << sum << endl;
}