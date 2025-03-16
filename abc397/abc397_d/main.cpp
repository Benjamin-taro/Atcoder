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

long long isqrt128(__int128 x) {
    // 「二分探索」で sqrt を整数的に求める
    // 今回 x は最大でもおよそ 1.2×10^19 (n=1e18, d=1 の場合など) なので，
    // 探索範囲は 0～1e10 程度あれば十分 (1e10^2 = 1e20)
    long long left = 0;
    long long right = (long long)1e10; 
    while (right - left > 1) {
        long long mid = (left + right) >> 1;
        __int128 sq = ( __int128 )mid * mid;
        if (sq <= x) left = mid;
        else         right = mid;
    }
    return left;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    // d = x - y を走査 (ただし d^3 <= n)
    // ここで x^3 - y^3 = n  => (y + d)^3 - y^3 = n
    // => n = d (3y^2 + 3dy + d^2)
    // => 3y^2 + 3dy + d^2 = n/d = m
    // => 3y^2 + 3dy + (d^2 - m) = 0  (二次方程式)
    for (long long d = 1; d*d*d <= n; d++) {
        if (n % d != 0) continue; // dがnの約数でなければ意味がない

        long long m = n / d; // m = n/d

        // 判別式 disc = b^2 - 4ac
        // ここで a=3, b=3d, c=(d^2 - m)
        // => disc = (3d)^2 - 4*3*(d^2 - m)
        //          = 9d^2 - 12(d^2 - m)
        //          = 9d^2 - 12d^2 + 12m
        //          = -3d^2 + 12m
        //          = 12*m - 3*d^2
        // 64bit でオーバーフローする可能性があるので __int128 を使用
        __int128 disc128 = ( __int128 )12 * m - ( __int128 )3 * d * d;
        if (disc128 < 0) {
            // disc < 0 なら実数解なし
            continue;
        }

        // disc128 が完全平方かどうかを 128bit のまま二分探索で判定
        long long sq = isqrt128(disc128);
        if ((__int128)sq * sq != disc128) {
            // ぴったり平方数でなければ 2次方程式に整数解は存在しない
            continue;
        }

        // 2つの解: k = [-b ± sqrt(disc)] / (2a) = [-3d ± sq] / 6
        // sign = +1 or -1
        for (int sign : {+1, -1}) {
            __int128 numerator = -3LL * d + sign * sq;  
            // 整数解になるには 6 で割り切れる必要がある
            if (numerator % 6 != 0) continue;

            __int128 k128 = numerator / 6;
            // 今回は y=k > 0 を想定 (正の解のみ欲しい)
            if (k128 <= 0) continue;

            // k128 を long long に落とせる範囲か (念のためチェック)
            if (k128 > LLONG_MAX) continue;

            long long k = (long long)k128;
            long long x = k + d; 
            long long y = k;
            if (x <= 0 || y <= 0) continue; 
            
            // 念のため (x^3 - y^3 == n) を __int128 で厳密チェック
            __int128 lhs = (__int128)x*x*x - (__int128)y*y*y;
            if (lhs == n) {
                // 見つかったら出力して終了
                cout << x << " " << y << "\n";
                return 0;
            }
        }
    }

    // ここまで来ても見つからなければ -1
    cout << -1 << "\n";
    return 0;
}