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

using namespace std;

const string YES = "Yes";
const string NO = "No";

// 頂点間のベクトルのクロス積を計算する関数
int64_t cross_product(int64_t ax, int64_t ay, int64_t bx, int64_t by) {
    return ax * by - ay * bx;
}

// 四角形が凸であるかどうかを判定する関数
bool is_convex(const vector<int64_t>& X, const vector<int64_t>& Y) {
    vector<int64_t> cross_products;
    
    for (int i = 0; i < 4; ++i) {
        int64_t ax = X[(i + 1) % 4] - X[i];
        int64_t ay = Y[(i + 1) % 4] - Y[i];
        int64_t bx = X[(i + 2) % 4] - X[(i + 1) % 4];
        int64_t by = Y[(i + 2) % 4] - Y[(i + 1) % 4];
        cross_products.push_back(cross_product(ax, ay, bx, by));
    }

    // 全てのクロス積が同じ符号を持っているか確認
    bool all_positive = all_of(cross_products.begin(), cross_products.end(), [](int64_t cp) { return cp > 0; });
    bool all_negative = all_of(cross_products.begin(), cross_products.end(), [](int64_t cp) { return cp < 0; });

    return all_positive || all_negative;
}

int main() {
    vector<int64_t> X(4), Y(4);
    
    // 頂点の座標を入力
    for (int i = 0; i < 4; ++i) {
        cin >> X[i] >> Y[i];
    }
    
    // 凸四角形かどうかを判定して結果を出力
    cout << (is_convex(X, Y) ? YES : NO) << endl;
    
    return 0;
}