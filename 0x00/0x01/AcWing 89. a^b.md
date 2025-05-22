```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 power(i64 a, int b, int p) {
    i64 res = 1 % p;
    for (; b; b >>= 1, a = a * a % p) {
        if (b & 1) {
            res = res * a % p;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, p;
    cin >> a >> b >> p;

    cout << power(a, b, p) << '\n';

    return 0;
}
```