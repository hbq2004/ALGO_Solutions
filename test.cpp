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

void solve() {
    int m, h;
    cin >> m >> h;
    
    i64 res = 0;
    while (h--) {
        int a, b;
        cin >> a >> b;
        res = (res + power(a, b, m)) % m;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}