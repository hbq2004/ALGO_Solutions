[yxc - Tutorial](https://www.acwing.com/solution/content/1065/) 

```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1010;

int n, root;
struct Node {
    int p, s, v;
    double avg;
} nodes[N];

/*

p: 父节点
s: 点数
v: 点权和
avg: 平均点权

*/

int find() { // 返回当前，没有被删除，且平均点权 avg 最大的点
    double avg = 0;
    int id = -1;
    for (int i = 1; i <= n; i++) {
        if (i != root && nodes[i].avg > avg) {
            avg = nodes[i].avg;
            id = i;
        }
    }
    return id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> root;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].v;
        nodes[i].avg = nodes[i].v;
        nodes[i].s = 1;
        ans += nodes[i].v;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        nodes[b].p = a;
    }

    for (int i = 0; i < n - 1; i++) {
        int p = find(); // 当前权值最大的点
        int father = nodes[p].p;
        ans += nodes[p].v * nodes[father].s; // 更新答案增量 ***
        nodes[p].avg = -1; // 删掉这个点
        for (int j = 1; j <= n; j++) { // 将当前这个点与其父节点合并
            if (nodes[j].p == p) {
                nodes[j].p = father; // 待合并的点 p 可能是一个点集
            }
        }
        // 更新父节点信息
        nodes[father].v += nodes[p].v;
        nodes[father].s += nodes[p].s;
        nodes[father].avg = 1.0 * nodes[father].v / nodes[father].s;
    }

    cout << ans << '\n';

    return 0;
}
```

