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


const string YES = "Yes";
const string NO = "No";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, s;
    cin >> n >> s;

    vector<int64_t> a(n);
    int64_t total_sum = 0;

    // 入力と合計の計算
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    // sを全体の合計で剰余を取る
    s %= total_sum;
    if (s == 0) {
        cout << YES << endl;
        return 0;
    }

    // 配列を2倍にして累積和を構築
    vector<int64_t> b = a;
    b.insert(b.end(), a.begin(), a.end() - 1); // 配列をつなげる
    int m = b.size();
    vector<int64_t> b_prefix(m + 1, 0);

    for (int i = 0; i < m; ++i) {
        b_prefix[i + 1] = b_prefix[i] + b[i];
    }

    // 二分探索で条件を満たす部分列を探す
    for (int j = 1; j <= m; ++j) {
        int64_t required = b_prefix[j] - s;
        if (binary_search(b_prefix.begin(), b_prefix.begin() + j, required)) {
            cout << YES << endl;
            return 0;
        }
    }

    cout << NO << endl;
    return 0;
}