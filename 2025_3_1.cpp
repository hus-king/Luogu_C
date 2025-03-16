#include <bits/stdc++.h>
using namespace std;

void count(long long k, long long t, long long M) {
    long long x = 1;
    int count1 = 0, count0 = 0, count10 = 0;
    for (long long i = 0; i < k; ++i) {
        string s = to_string(x);
        int key1 = (s.find('1') != string::npos);
        int key0 = (s.find('0') != string::npos);
        if (key1) count1++;
        if (key0) count0++;
        if (key1 && key0){
            count10++;
            count1--;
            count0--;
        }
        x = (x + t) % M;
    }
    cout << count1 << " " << count0 << " " << count10 << endl;
}

int main() {
    long long k, t, M;
    cin >> k >> t >> M;
    count(k, t, M);
    return 0;
}