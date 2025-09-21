#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

const int MAXN = 16;
const int MAXSTATE = 1 << MAXN;
double memo[MAXSTATE][MAXN]; // memo[mask][pos]

int n;
int history = 0;
int now_index = 0;
int now_num = 0;
double current_distance = 0;
double ans = DBL_MAX;

vector<bool> visited;
struct Point {
    double x, y;
};
vector<Point> points(20);

double calculate_distance(int a, int b) {
    double dx = points[a].x - points[b].x;
    double dy = points[a].y - points[b].y;
    return sqrt(dx * dx + dy * dy);
}

void dfs() {
    // ✅ 用数组直接查，无需构造 state_key
    if (memo[history][now_index] <= current_distance) {
        return; // 剪枝：已有更优或相等解
    }
    memo[history][now_index] = current_distance;

    if (current_distance >= ans) {
        return; // 剪枝：超过全局最优
    }

    if (now_num == n) {
        ans = min(ans, current_distance);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int bit = (1 << i);
            history |= bit;
            visited[i] = true;

            double d = calculate_distance(now_index, i);
            current_distance += d;

            int prev_index = now_index;
            now_index = i;
            now_num++;

            dfs();

            // 回溯
            now_index = prev_index;
            current_distance -= d;
            visited[i] = false;
            history &= ~bit;
            now_num--;
        }
    }
}

int main() {
    cin >> n;
    points.resize(n + 1);
    visited.resize(n + 1, false);
    points[0] = {0, 0};

    // ✅ 初始化 memo 数组
    for (int i = 0; i < MAXSTATE; i++) {
        for (int j = 0; j < MAXN; j++) {
            memo[i][j] = DBL_MAX;
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    dfs();
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
// #include <bits/stdc++.h>
// #include <iomanip>
// using namespace std;

// unordered_map<int, double> record; // 记录状态
// int n;
// int history = 0;          // 用位掩码记录访问状态
// int now_index = 0;        // 当前所在点编号（0是起点，1~n是奶酪）
// int now_num = 0;          // 已访问奶酪数
// double current_distance = 0;
// double ans = DBL_MAX;

// vector<bool> visited;
// struct Point {
//     double x, y; // ✅ 改为 double，支持小数坐标
// };
// vector<Point> points(20);

// double calculate_distance(int a, int b) {
//     double dx = points[a].x - points[b].x;
//     double dy = points[a].y - points[b].y;
//     return sqrt(dx * dx + dy * dy);
// }

// void dfs() {
//     int state_key = (history << 4) | now_index;
//     if (record.count(state_key)){
//         if(record[state_key] <= current_distance) return;
//         else record[state_key] = current_distance;
//     }
//     if (current_distance >= ans) return;
//     record[state_key] = current_distance;
//     if (now_num == n) {
//         ans = min(ans, current_distance);
//         return;
//     }
//     for (int i = 1; i <= n; i++) {
//         if (!visited[i]) {
//             int bit = (1 << i);
//             history |= bit;               // 设置第 i 位
//             double d = calculate_distance(now_index, i);
//             current_distance += d;
//             visited[i] = true;
//             int temp = now_index;
//             now_index = i;
//             now_num++;
//             dfs();
//             now_index = temp;
//             current_distance -= d;
//             visited[i] = false;
//             history &= ~bit;              // 清除第 i 位
//             now_num--;
//         }
//     }
// }

// int main() {
//     cin >> n;
//     points.resize(n + 1);
//     visited.resize(n + 1, false);
//     points[0] = {0, 0}; // 起点

//     for (int i = 1; i <= n; i++) {
//         cin >> points[i].x >> points[i].y;
//     }

//     dfs();
//     cout << fixed << setprecision(2) << ans << endl;
//     return 0;
// }