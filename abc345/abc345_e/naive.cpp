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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18; // 十分に大きな値

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> C(N + 1), V(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> C[i] >> V[i];
    }

    // dp[i][j] は、最初の i 個のボールを見て、j 個のボールを取り除いたときの最大の価値の合計
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, -INF));

    dp[0][0] = 0; // 何も取り除かない状態の価値は 0

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            // ボールを取り除かない場合
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + (j > 0 && C[i] != C[i - 1] ? V[i] : 0));
            
            // ボールを取り除く場合（もし可能なら）
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }

    long long result = dp[N][K];
    if (result < 0) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
