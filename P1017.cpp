#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    string result;
    const int abs_r = abs(r); // 获取基数的绝对值
    
    if (n == 0) { // 处理输入为0的特殊情况
        cout << "0=0(base" << r << ")" << endl;
        return 0;
    }

    int original = n; // 保存原始值用于输出
    while (n != 0) {
        int remainder = n % r; // 直接对负数取余
        n /= r;
        
        // 处理负余数（关键优化点）
        if (remainder < 0) {
            remainder += abs_r; // 调整余数为正数
            n += 1;            // 调整商值
        }
        
        // 处理数字表示（根据基数绝对值判断字母）
        if (abs_r > 10) {
            result.push_back(remainder > 9 ? 'A' + remainder - 10 : '0' + remainder);
        } else {
            result.push_back('0' + remainder);
        }
    }

    reverse(result.begin(), result.end());
    cout << original << "=" << result << "(base" << r << ")" << endl;
    return 0;
}