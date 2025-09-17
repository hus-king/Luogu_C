#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    unordered_map<int, int> next_node; // 当前节点 -> 下一节点
    next_node[1] = 0; // 初始只有一个元素 1，后面没有元素
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;// 插入 y 到 x 后面
            next_node[y] = next_node[x]; // y 指向 x 原来的下一个
            next_node[x] = y;             // x 现在指向 y
        } else if (op == 2) {
            int x;
            cin >> x;
            cout << next_node[x] << '\n';
        } else if (op == 3) {
            int x;
            cin >> x;
            int to_delete = next_node[x];
            if (to_delete != 0) {
                next_node[x] = next_node[to_delete]; // 跳过要删除的节点
                next_node.erase(to_delete);          // 删除该节点
            }
        }
    }
    return 0;
}