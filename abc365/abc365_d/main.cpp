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
#include <cstring>
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

// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

//listing the prime numbers until N
vector<int64_t> findPrimes(int64_t N) {
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int64_t i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int64_t j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int64_t> primes;
    for (int64_t i = 2; i <= N; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

//Checking given number is prime or not
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }
    return true;
}




int64_t solve(int64_t N, const std::string &S) {
    // dp[i][j] : iラウンド目まで進んだとき、jの手で勝った最大回数
    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(3, -1));

    // 初期条件
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (dp[i][j] == -1) continue; // 有効な状態でない場合は無視

            if (S[i] == 'P') {
                // グーを出す場合 (負けるので無視)
                // チョキを出す場合 (勝つ)
                if (j != 1) dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + 1);
                // パーを出す場合 (引き分け)
                if (j != 2) dp[i + 1][2] = max(dp[i + 1][2], dp[i][j]);
            } else if (S[i] == 'R') {
                // チョキを出す場合 (負けるので無視)
                // パーを出す場合 (勝つ)
                if (j != 2) dp[i + 1][2] = max(dp[i + 1][2], dp[i][j] + 1);
                // グーを出す場合 (引き分け)
                if (j != 0) dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
            } else if (S[i] == 'S') {
                // パーを出す場合 (負けるので無視)
                // グーを出す場合 (勝つ)
                if (j != 0) dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + 1);
                // チョキを出す場合 (引き分け)
                if (j != 1) dp[i + 1][1] = max(dp[i + 1][1], dp[i][j]);
            }
        }
    }

    return max({dp[N][0], dp[N][1], dp[N][2]});
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t N;
    std::string S;
    std::cin >> N >> S;

    auto ans = solve(N, S);
    std::cout << ans << '\n';
    return 0;
}