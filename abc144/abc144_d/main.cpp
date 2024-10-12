#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using ld = long double;

void solve() {
    ld a, b, x;
    std::cin >> a >> b >> x;

    if (x > a * a * b / 2) {
        x = a * a * b - x;

        x /= a * a / 2;
        std::cout << std::atan(x / a) / std::acos(-1) * 180;
    } else {
        x /= a * b / 2;

        std::cout << std::atan(b / x) / std::acos(-1) * 180;
    }
}

signed main() {
    std::cin.tie(0) -> sync_with_stdio(false);
    int t = 1;
    //std::cin >> t;
    std::cout << std::setprecision(7) << std::fixed;
    while(t--) solve();
    return 0;
}