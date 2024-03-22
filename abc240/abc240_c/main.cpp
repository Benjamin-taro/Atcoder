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
#include <cstring>
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





const std::string YES = "Yes";
const std::string NO = "No";

const int MAX_N = 100;
int64_t memo[MAX_N + 1][10001]; // メモ化用の配列

bool jump(int64_t cnt, int64_t posi, int64_t N, int64_t X, const vector<int64_t>& a, const vector<int64_t>& b) {
    // Check for memoization
    if (memo[cnt][posi] != -1) {
        return memo[cnt][posi];
    }

    // Base case
    if (cnt == N) {
        return memo[cnt][posi] = (posi == X);
    }

    // Recursive computation and memoization
    bool res = jump(cnt + 1, posi + a[cnt], N, X, a, b) || jump(cnt + 1, posi + b[cnt], N, X, a, b);
    memo[cnt][posi] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int64_t X;

    // Initialize memo array to -1
    memset(memo, -1, sizeof(memo));

    cin >> N >> X;
    vector<int64_t> a(N), b(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i] >> b[i];
    }
    bool ans = jump(0, 0, N, X, a, b);
    cout << (ans ? YES : NO) << '\n';

    return 0;
}