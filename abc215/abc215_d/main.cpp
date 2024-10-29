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

// 素数判定関数
bool IsPrime(int64_t num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false; // 偶数を除く

    int sqrtNum = static_cast<int>(sqrt(num));
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) return false; // 素数ではない
    }
    return true;
}

auto solve(int N, int64_t M, const vector<int64_t> &A) {
    set<int64_t> unique_divisors;

    // 各A[i]の素因数を見つける
    for (int i = 0; i < N; i++) {
        for (int j = 1; j * j <= A[i]; j++) {
            if (A[i] % j == 0) {
                if (IsPrime(j)) unique_divisors.insert(j);
                if (j != A[i] / j && IsPrime(A[i] / j)) unique_divisors.insert(A[i] / j);
            }
        }
    }
    vector<int64_t> ans;
    for(int i = 1; i <= M; i++) {
        bool is_ok = true;
        for (auto divisor : unique_divisors) {
            if (i % divisor == 0) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) ans.push_back(i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int64_t M;
    cin >> N >> M;
    vector<int64_t> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    auto ans = solve(N, M, A);
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << endl;
    }
    return 0;
}