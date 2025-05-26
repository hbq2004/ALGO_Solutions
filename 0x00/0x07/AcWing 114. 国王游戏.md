
# 邻项交换（微扰）贪心

---

考虑最终序列中的相邻两项的相对位置，**其余项不受影响**，根据参数列出对应的方程，求相对顺序与参数的大小关系的不等式，从而得到相邻两项最优秀的**逆序对关系**。

再根据冒泡排序的知识，**任何一个序列都可以通过邻项交换的方式变成有序序列**，故当逆序对的数量为 $0$，达到最后策略。

---

此题比较恶心的是需要写一个高精度来排序，和计算最终答案。

```cpp
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

constexpr int N = 1010;

int n;
PII a[N];

bool cmp(vector<int> &A, vector<int> &B) { // a < b
	if (A.size() != B.size()) return A.size() < B.size();
	for (int i = A.size() - 1; i < n; i++) {
		if (A[i] != B[i]) {
			return A[i] < B[i];
		}
	}
	return false;
}

vector<int> mul(vector<int> &A, int b) {
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || t; i++) {
		if (i < A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	
	return C;
}

vector<int> div(vector<int> &A, int b) {
	vector<int> C;
	int r = 0;
	for (int i = A.size() - 1; i >= 0; i--) {
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	
	return C;
}

void print(vector<int> &A) {
	for (int i = A.size() - 1; i >= 0; i--) {
		cout << A[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i <= n; i++) cin >> a[i].x >> a[i].y;
	
	sort(a + 1, a + 1 + n, [&](PII p, PII q) {
		return p.x * p.y < q.x * q.y;
	});
	
	vector<int> mx(1, 0), s(1, 1);
	s = mul(s, a[0].x);
	for (int i = 1; i <= n; i++) {
		auto tmp = div(s, a[i].y);
		if (cmp(mx, tmp)) {
			mx = tmp;
		}
		s = mul(s, a[i].x);
	}
	
	print(mx);
	
	return 0;
}
```