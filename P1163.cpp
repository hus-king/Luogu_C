#include <bits/stdc++.h>
using namespace std;
int P, A, n;

double check(double r) {
    double x = pow(1 + r, n);
    return P * r * x / (x - 1);
}

int main() {
    cin >> P >> A >> n;
    double left = 0, right = 3.0; // 300% = 3.0
    while (right - left > 1e-8) {
        double mid = (left + right) / 2;
        if (check(mid) < A)
            left = mid;
        else
            right = mid;
    }
    // 四舍五入到0.1%
    double ans = right * 100;
    printf("%.1f\n", ans);
    return 0;
}