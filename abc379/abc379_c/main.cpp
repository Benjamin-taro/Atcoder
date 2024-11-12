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
#include <unordered_set>
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
#include <iomanip>  // 追加: 出力精度を指定するため
#include <tuple>
#include <chrono>
#include <random>
#include <functional>
#include <iterator>
#include <cctype>
#include <limits>
#include <cassert>
#include <complex>
#include <sstream>
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

class PrimeSieve {
public:
    PrimeSieve(int max_num) : max_num(max_num), is_prime(max_num + 1, true) {
        run_sieve();
    }

    // 素数判定
    bool isPrime(int num) const {
        if (num < 0 || num > max_num) return false;
        return is_prime[num];
    }

    // 素数のリストを取得
    std::vector<int> getPrimes() const {
        std::vector<int> primes;
        for (int i = 2; i <= max_num; i++) {
            if (is_prime[i]) primes.push_back(i);
        }
        return primes;
    }

private:
    int max_num;
    std::vector<bool> is_prime;

    // エラトステネスの篩を実行
    void run_sieve() {
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= max_num; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= max_num; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
};

int64_t solve(int64_t N, int64_t M, const vector<int64_t> &X, const vector<int64_t> &A) {
    int64_t ans = 0;
    int64_t current_position = N;
    int64_t total_stones = 0;

    // まず、全ての石の合計が N を超えていないかチェック
    for (int i = 0; i < M; i++) {
        total_stones += A[i];
    }
    if (total_stones < N) {
        return -1;
    }

    // ペアとしてXとAをまとめてソート
    vector<pair<int64_t, int64_t>> P(M);
    for (int i = 0; i < M; i++) {
        P[i] = {X[i], A[i]};
    }
    // X を降順にソート
    sort(P.rbegin(), P.rend());

    // 右から左に向かって処理
    for (int i = 0; i < M; i++) {
        int64_t start = P[i].first;
        int64_t stones = P[i].second;

        // 現在の区間で必要なマス数をチェック
        if (current_position - start + 1 < stones) {
            return -1;  // 必要な石が足りない場合
        }

        // 現在の位置からこの区間の開始位置までの距離を計算（1-indexed を考慮）
        int64_t distance = current_position - start;

        // 操作回数を計算
        if (distance == stones - 1) {
            ans += (distance + 1) * distance / 2;
            current_position = start - 1;  // 次の区間に進む
        } else {
            ans += ((distance + 1) * distance / 2) - ((distance - stones + 1) * (distance - stones) / 2);
            current_position -= stones; // `-stones` して次の区間の基準に
        }
    }

    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t N;
    int64_t M;
    std::cin >> N >> M;
    std::vector<int64_t> X(M), A(M);
    REP(i, M) {
        std::cin >> X[i];
    }
    REP(i, M) {
        std::cin >> A[i];
    }
    auto ans = solve(N, M, X, A);
    std::cout << ans << '\n';
    return 0;
}
