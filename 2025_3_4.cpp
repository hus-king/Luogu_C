#include <bits/stdc++.h>
using namespace std;
vector<int> stringtoint(string s);
int check(int x, int y);
int main(){
    int n;
    cin >> n;
    string a;
    string b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        vector<int> x = stringtoint(a);
        vector<int> y = stringtoint(b);
        vector<int> result(4);
        for(int j = 0; j < 4; j++){
            result[j] = y[j] - x[j];
            if(result[j] > 5) result[j] -= 10;
            if(result[j] < -4) result[j] += 10;
        }
        int step = 0;
        while(result[0] != 0 || result[1] != 0 || result[2] != 0 || result[3] != 0){
            int length[4]={1,1,1,1};
            int start[4]={0};
            int end[4]={0};
            for(int i = 0; i < 4; i++){
                start[i] = i;
                end[i] = i;
                for(int k=i+1;k<4;k++){
                    int flag;
                    for(int j=i;j<k;j++){
                        if(check(result[j],result[k])) flag = 1;
                        else{
                            flag = 0;
                            break;
                        }
                    }
                    if(flag){
                        length[i]++;
                        end[i] = k;
                    }
                    else break;
                }
            }
            int max = 0;
            int maxindex = 0;
            for(int i = 0; i < 4; i++){
                if(result[i] == 0) continue;
                if(length[i] >= max){
                    max = length[i];
                    maxindex = i;
                }
            }
            int add = 0;
            int min = 10;
            int minindex = 0;
            for(int i = start[maxindex]; i <= end[maxindex]; i++){
                if(abs(result[i]) < min){
                    min = abs(result[i]);
                    minindex = i;
                }
            }
            add = result[minindex];
            step += abs(add);
            for(int i = start[maxindex]; i <= end[maxindex]; i++){
                result[i] -= add;
            }
            for(int i = 0; i < 4; i++){
                if(result[i] > 5) result[i] -= 10;
                if(result[i] < -4) result[i] += 10;
            }
        }
        cout << step << endl;
    }
}
vector<int> stringtoint(string s){
    int n = s.size();
    vector<int> x(4);
    for(int i = 0; i < n; i++){
        x[i] = s[i] - '0';
    }
    return x;
}
int check(int x, int y){
    if(x == 5 || y == 5) return 1;
    else if(x == 0 || y == 0) return 0;
    else if(x * y > 0) return 1;
    else return 0;
}