#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    int x, y;
    cin >> x >> y;
    int key = 0;
    for(int i = x; i <= y; i += x) {
        int j = x * y / i;
        if(i*j == x*y && gcd(i, j) == x) key++;
    }
    cout << key << endl;
}