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



const long long INF = 1e18; // 十分に大きな値

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    int64_t K;
    std::cin >> N;
    std::cin >> K;
    vector<int> C(N + 1), V(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> C[i] >> V[i];
    }

    // dp[i][j] は、最初の i 個のボールを見て、j 個のボールを取り除いたときの最大の価値の合計
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, -INF));


    dp[0][0] = 0;
    for(int64_t i = 1; i<N; i++){
        for(int64_t j = 0; j<K; j++){
            if(j == 0 || C[i] != C[i-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j] + V[i]);
            }
            if(j>0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }

    long long result = -1;
    //for (int j = 0; j <= K; ++j) {
    result = max(result, dp[N][K]);
    //}


    if (result < 0) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;

}
