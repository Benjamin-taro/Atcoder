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
#include <stack>
#include <unordered_map>
#include <type_traits> // For std::is_floating_point
#include <cmath> // For std::ceil
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
//文字配列の二次元配列みたいなやつを回転させる。
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






auto solve(int64_t N, int M, const std::vector<int64_t> &a, const std::vector<int64_t> &b, int Q, const std::vector<int64_t> &s, const std::vector<int64_t> &t) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t N;
    int M, Q;
    std::cin >> N >> M;
    std::vector<int64_t> a(M), b(M);
    REP (i, M) {
        std::cin >> a[i] >> b[i];
    }
    std::cin >> Q;
    std::vector<int64_t> s(Q), t(Q);
    REP (i, Q) {
        std::cin >> s[i] >> t[i];
    }
    auto ans = solve(N, M, a, b, Q, s, t);
    std::cout << n << '\n';
    REP (i, n) {
        std::cout << a1[i] << '\n';
    }
    return 0;
}