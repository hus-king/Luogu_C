#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int m,n;
    vector<int> school,student;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        school.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        student.push_back(x);
    }
    sort(school.begin(), school.end()); //从小到大排序
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int score = student[i];
        int l = 0, r = m - 1;
        int mid;
        int mind = 1e6;
        while(r >= l){
            mid = (l + r) / 2;
            if(school[mid] >= score){
                r = mid - 1;
                mind = min(mind, school[mid] - score); 
            }
            else{
                l = mid + 1;
                mind = min(mind, score - school[mid]);
            }
        }
        sum += mind;
    }
    cout << sum << endl;
    return 0;
}