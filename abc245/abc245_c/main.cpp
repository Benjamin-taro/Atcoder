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

const string YES = "Yes";
const string NO = "No";

bool solve(int N, int64_t K, const vector<int64_t> &A, const vector<int64_t> &B) {
    vector<vector<bool>> dp(N, vector<bool>(2, false));
    dp[0][0] = dp[0][1] = true; // 初期値として、最初の要素はどちらを選んでもOK

    for (int i = 1; i < N; ++i) {
        if (dp[i-1][0] && abs(A[i] - A[i-1]) <= K) dp[i][0] = true;
        if (dp[i-1][1] && abs(A[i] - B[i-1]) <= K) dp[i][0] = true;
        if (dp[i-1][0] && abs(B[i] - A[i-1]) <= K) dp[i][1] = true;
        if (dp[i-1][1] && abs(B[i] - B[i-1]) <= K) dp[i][1] = true;
    }

    return dp[N-1][0] || dp[N-1][1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int64_t K;
    cin >> N >> K;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    cout << (solve(N, K, A, B) ? YES : NO) << '\n';
    return 0;
}
