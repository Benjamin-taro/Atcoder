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


void solve(int64_t n, int64_t m) {
    set<pair<int64_t, int64_t>> possible_moves;
    int64_t limit = min(sqrt(m), static_cast<double>(n));
    for(int64_t i = 0; i < limit; ++i) {
        int64_t j = m - i * i;
        if (j < 0) continue;
        // j が完全平方数かどうかをチェック
        int64_t sqrt_j = static_cast<int64_t>(sqrt(j));
        if (sqrt_j * sqrt_j == j) {
            if (i < n && sqrt_j < n) {
                possible_moves.insert({i, sqrt_j});
                possible_moves.insert({-i, sqrt_j});
                possible_moves.insert({i, -sqrt_j});
                possible_moves.insert({-i, -sqrt_j});
                possible_moves.insert({sqrt_j, i});
                possible_moves.insert({-sqrt_j, i});
                possible_moves.insert({sqrt_j, -i});
                possible_moves.insert({-sqrt_j, -i});
        
            }
        }
    }
    vector<vector<int64_t>> ans(n, vector<int64_t>(n, -1));
    ans[0][0] = 0;
    queue<pair<int64_t, int64_t>> q;
    q.push({0, 0});
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(auto& move : possible_moves) {
            int64_t nx = x + move.first;
            int64_t ny = y + move.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && ans[nx][ny] == -1) {
                ans[nx][ny] = ans[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for(int64_t i = 0; i < n; ++i) {
        for(int64_t j = 0; j < n; ++j) {
            cout << ans[i][j];
            if (j != n - 1) cout << " ";
        }
        cout << "\n";
    }
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n, m;
    std::cin >> n >> m;
    solve(n, m);
    return 0;

}
