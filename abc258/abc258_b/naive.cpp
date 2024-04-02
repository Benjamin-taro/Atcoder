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

int mod(int x, int m) {
    int r = x % m;
    return r < 0 ? r + m : r;
}

int64_t dfs(int64_t N, const vector<string>& A, int i, int j, int64_t cnt, vector<vector<bool>>& visited) {
    if (cnt == N) { // 全セルを訪れたときの終了条件に変更
        return 0;
    }
    
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    visited[i][j] = true;
    int64_t maxValue = 0; // 各セルからスタートした際の最大値を格納する変数

    for (int k = 0; k < 4; ++k) {
        int ni = mod(i + dx[k], N);
        int nj = mod(j + dy[k], N);
        
        if (!visited[ni][nj]) {
            int64_t pathValue = (A[i][j]-'0') * pow(10, N - 1 - cnt) + dfs(N, A, ni, nj, cnt + 1, visited);
            maxValue = max(maxValue, pathValue); // 最大値を更新
        }
    }
    
    visited[i][j] = false; // バックトラック
    return maxValue;
}

int64_t solve(int64_t N, vector<string> A) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int64_t maxPathValue = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maxPathValue = max(maxPathValue, dfs(N, A, i, j, 0, visited));
        }
    }
    return maxPathValue;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t N;
    std::cin >> N;
    std::vector<string> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    auto ans = solve(N, A);
    std::cout << ans << '\n';
    return 0;
}