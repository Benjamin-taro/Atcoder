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

vector<string> rotate90(const vector<string>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<string> rotated(m, string(n, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }
    return rotated;
}

void solve(int64_t H, int64_t W, vector<string>& a) {
    vector<bool> height(H, false);
    vector<bool> width(W, false);

    // 行のチェック
    for (int64_t i = 0; i < H; i++) {
        for (int64_t j = 0; j < W; j++) {
            if (a[i].find_first_not_of('.') != std::string::npos) {
                height[i] = true;
                break;
            }
        }
    }
    vector<string> a_a = rotate90(a);
    // 列のチェック
    for (int64_t i = 0; i < W; i++) {
        for (int64_t j = 0; j < H; j++) {
            if (a_a[i].find_first_not_of('.') != std::string::npos) {
                width[i] = true;
                break;
            }
        }
    }

    // 有効なセルの出力
    for (int64_t i = 0; i < H; i++) {
        if (!height[i]) continue;
        for (int64_t j = 0; j < W; j++) {
            if (width[j]) {
                cout << a[i][j];
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (int j = 0; j < H; j++) {
        cin >> a[j];
    }

    solve(H, W, a);
    return 0;
}
