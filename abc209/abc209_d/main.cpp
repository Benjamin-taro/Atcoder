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




int64_t solve(const map<int64_t, vector<int64_t>> &mp, int64_t c, int64_t d){
    // BFSで距離を計算
    vector<int64_t> dist(mp.size() + 1, -1); // mp.size() + 1 にすることで、1-indexed に対応
    queue<int64_t> q;
    q.push(c);
    dist[c] = 0;

    while (!q.empty()) {
        int64_t v = q.front();
        q.pop();
        for (int64_t nv : mp.at(v)) {
            if (dist[nv] != -1) continue; // すでに訪れているノードはスキップ
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    cerr << "dist: " << dist[d] << endl;
    return dist[d];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t N, Q;
    std::cin >> N>> Q;
    std::map<int64_t, vector<int64_t>> mp;

    // グラフの辺の入力を受け取る
    for (int64_t i = 0; i < N - 1; ++i) {
        int64_t a, b;
        std::cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    // 隣接リストのデバッグ出力
    for (const auto& [key, value] : mp) {
        cerr << "Node " << key << ": ";
        for (int64_t v : value) {
            cerr << v << " ";
        }
        cerr << endl;
    }

    // 頂点1からの深さを求める
    vector<int64_t> dist(N + 1, -1);  // -1で初期化して未訪問を表す
    queue<int64_t> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int64_t v = q.front();
        q.pop();
        for (int64_t nv : mp[v]) {
            if (dist[nv] != -1) continue; // すでに訪れているノードはスキップ
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    // デバッグ用に深さを出力
    for (int64_t i = 1; i <= N; ++i) {
        cerr << "dist[" << i << "]: " << dist[i] << endl;
    }

    for(int64_t i = 0; i < Q; ++i){
        int64_t c, d;
        std::cin >> c >> d;
        int64_t ans = dist[c] + dist[d];
        if(ans % 2 == 0){
            std::cout << "Town" << std::endl;
        }else{
            std::cout << "Road" << std::endl;
        }
    }

    return 0;
}



