#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <array>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <numeric>
#include <assert.h>
#include <unordered_map>
#include <type_traits> // For std::is_floating_point
#include <cmath> // For std::ceil
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

bool isDivisible(double distance, double R) {
    double quotient = distance / R;
    // 許容誤差を設定
    double epsilon = 1e-6;

    // 割り算の結果と、その結果を丸めた値が等しいかどうかを確認
    return std::fabs(quotient - std::round(quotient)) < epsilon;
}

int64_t solve(int64_t R, int64_t X, int64_t Y) {
    double distance = sqrt(X*X + Y*Y);
    if (distance == 0) {
        return 0; // 目的地が原点の場合は移動不要
    }

    double steps = distance / R;

    if (distance < R) {
        return 2; // 目的地がR未満の距離にある場合は、少なくとも1ステップ必要
    } else if (std::fabs(steps - std::round(steps)) < 1e-6) {
        return std::round(steps); // 割り切れる場合、そのままのステップ数を返す
    } else {
        return std::ceil(steps); // 割り切れない場合、ステップ数を切り上げる
    }
}
// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t R, X, Y;
    std::cin >> R >> X >> Y;
    auto ans = solve(R, X, Y);
    std::cout << ans << endl;
    return 0;
}