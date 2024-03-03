#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

constexpr int64_t MOD = 998244353;

int64_t solve(int64_t D) {
    int64_t temp = 1000000000000;
    int64_t limit = sqrt(D);
    for (int64_t x = 0; x <= limit; x++) {
        int64_t y = sqrt(D - x * x); // 直接yの値を計算
        // y周辺の値に対して微調整を行い、最適な解を見つける
        for (int64_t dy = -2; dy <= 2; dy++) {
            if (y + dy >= 0 && y + dy <= limit) {
                temp = min(temp, abs(x * x + (y + dy) * (y + dy) - D));
            }
        }
    }
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t D;
    cin >> D;
    auto ans = solve(D);
    cout << ans << '\n';
    return 0;
}
