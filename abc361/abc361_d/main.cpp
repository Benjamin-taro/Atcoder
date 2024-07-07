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
#include <unordered_set>
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



// 隣接する状態を生成する関数
vector<string> get_neighbors(const string &state) {
    vector<string> neighbors;
    int N = state.size();

    // 連続する空きマスを探す
    for (int i = 0; i < N - 1; ++i) {
        if (state[i] == '.' && state[i + 1] == '.') {
            // 連続する空きマスを見つけた場合、そこに石を移動する
            for (int j = 0; j < N - 1; ++j) {
                if (state[j] != '.' && state[j + 1] != '.') {
                    string new_state = state;
                    swap(new_state[i], new_state[j]);
                    swap(new_state[i + 1], new_state[j + 1]);
                    neighbors.push_back(new_state);
                }
            }
        }
    }

    return neighbors;
}

// 最小移動回数を求める関数
int min_moves_to_target(int N, const string &start, const string &target) {
    queue<pair<string, int>> q;
    unordered_set<string> visited;
    unordered_map<string, string> parent;  // 親状態を保存するためのマップ

    q.push({start, 0});
    visited.insert(start);
    parent[start] = "";  // 初期状態の親は空文字列

    while (!q.empty()) {
        auto [current_state, moves] = q.front();
        q.pop();

        if (current_state == target) {
            // 経路を表示する
            vector<string> path;
            for (string s = target; !s.empty(); s = parent[s]) {
                path.push_back(s);
            }
            reverse(path.begin(), path.end());
            for (const string &s : path) {
                //cout << s << endl;
            }
            return moves;
        }

        for (const string &neighbor : get_neighbors(current_state)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, moves + 1});
                parent[neighbor] = current_state;  // 親状態を記録
            }
        }
    }

    return -1; // 目標状態に到達不可能な場合
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t N;
    std::string S, T;
    std::cin >> N >> S >> T;
    S += "..";
    T += "..";
    int result = min_moves_to_target(N, S, T);
    cout << result << endl;


    return 0;
}
