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
#include <iomanip>  // 追加: 出力精度を指定するため
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


// 2つのノードが接続されているかを確認する関数
bool are_connected(const map<int, vector<int>>& uf_map, int a, int b) {
    // aが接続されているノードのリストにbが存在するか確認
    if (uf_map.find(a) != uf_map.end()) {
        for (int connected_node : uf_map.at(a)) {
            if (connected_node == b) return true;
        }
    }
    return false;
}

// ノード間に辺を追加する関数
void add_edge(map<int, vector<int>>& uf_map, int a, int b) {
    uf_map[a].push_back(b);  // aからbへの接続を追加
    uf_map[b].push_back(a);  // bからaへの接続も追加（無向グラフの場合）
}

// ノード間の辺を削除する関数
void erase_edge(map<int, vector<int>>& uf_map, int a, int b) {
    // aからbを削除
    if (uf_map.find(a) != uf_map.end()) {
        auto& neighbors = uf_map[a];
        neighbors.erase(remove(neighbors.begin(), neighbors.end(), b), neighbors.end());
    }

    // bからaを削除
    if (uf_map.find(b) != uf_map.end()) {
        auto& neighbors = uf_map[b];
        neighbors.erase(remove(neighbors.begin(), neighbors.end(), a), neighbors.end());
    }
}

int solve(int n, int Mg, int Mh, map<int, vector<int>> uf1, map<int, vector<int>> uf2, vector<vector<int>> matrix) {
    int64_t cost = 0;  // 結果のコスト

    // 全てのノードペアを確認
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // uf1で連結しているが、uf2で連結していない場合 → uf2に新しい辺を追加
            if (are_connected(uf1, i, j) && !are_connected(uf2, i, j)) {
                add_edge(uf2, i, j);
                cost += matrix[i][j];  // コストを加算
                std::cerr << "Adding edge between " << i << " and " << j << " with cost " << matrix[i][j] << "\n";
            }
            // uf1で連結していないが、uf2で連結している場合 → 辺の削除
            else if (!are_connected(uf1, i, j) && are_connected(uf2, i, j)) {
                erase_edge(uf2, i, j);
                cost += matrix[i][j];  // コストを加算
                std::cerr << "Removing edge between " << i << " and " << j << " with cost " << matrix[i][j] << "\n";
            }
        }
    }

    return cost;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int Mg, Mh;
    std::cin >> Mg;
    map<int, vector<int>> uf1, uf2;

    // uf1の辺の入力
    for (int i = 0; i < Mg; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;  // 1インデックスから0インデックスに変換
        add_edge(uf1, a, b);
    }

    std::cin >> Mh;

    // uf2の辺の入力
    for (int i = 0; i < Mh; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;  // 1インデックスから0インデックスに変換
        add_edge(uf2, a, b);
    }

    // 2次元ベクトルの初期化 (n x n)
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    // 上三角部分のみを入力
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // 結果の計算
    int result = solve(n, Mg, Mh, uf1, uf2, matrix);

    std::cout << result << '\n';
    return 0;
}

