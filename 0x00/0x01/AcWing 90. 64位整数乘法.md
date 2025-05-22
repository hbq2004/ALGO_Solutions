```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 multiply(i64 a, i64 b, i64 p) {
    i64 res = 0;
    for (; b; b >>= 1, a = a * 2 % p) {
        if (b & 1) {
            res = (res + a) % p;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 a, b, p;
    cin >> a >> b >> p;

    cout << multiply(a, b, p) << '\n';

    return 0;
}
```