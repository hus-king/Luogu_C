#include <iostream>
#include <vector>
using namespace std;

vector<int> fac[60];

vector<int> multiply(vector<int> a, int b) {
    vector<int> result;
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        int product = a[i] * b + carry;
        result.push_back(product % 10);
        carry = product / 10;
    }
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
    return result;
}

vector<int> factorial(int n) {
    vector<int> ans(1, 1);
    for (int i = 1; i <= n; i++) {
        ans = multiply(ans, i);
        fac[i] = ans;
    }
    return ans;
}

void print(vector<int> num) {
    for (int i = num.size() - 1; i >= 0; i--) {
        cout << num[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> ans(1, 0);
    factorial(n);
    for (int i = 1; i <= n; i++) {
        vector<int> temp = ans;
        ans = vector<int>(max(ans.size(), fac[i].size()), 0);
        int carry = 0;
        for (int j = 0; j < ans.size(); j++) {
            if (j < temp.size()) ans[j] += temp[j];
            if (j < fac[i].size()) ans[j] += fac[i][j];
            ans[j] += carry;
            carry = ans[j] / 10;
            ans[j] %= 10;
        }
        while (carry) {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }
    print(ans);
    return 0;
}