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
#include <unordered_set>

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


struct Query {
    int L, R, idx;
};

int BLOCK_SIZE;

// クエリをブロックごとにソートするための比較関数
bool compare(Query q1, Query q2) {
    if (q1.L / BLOCK_SIZE != q2.L / BLOCK_SIZE)
        return q1.L / BLOCK_SIZE < q2.L / BLOCK_SIZE;
    return q1.R < q2.R;
}

void add(int value, unordered_map<int, int>& count, int& distinct_count) {
    count[value]++;
    if (count[value] == 1) {
        distinct_count++;
    }
}

void remove(int value, unordered_map<int, int>& count, int& distinct_count) {
    count[value]--;
    if (count[value] == 0) {
        distinct_count--;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    BLOCK_SIZE = sqrt(N);

    // クエリは全ての (i, j) を考えるので N * (N + 1) / 2 のクエリがある
    vector<Query> queries;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            queries.push_back({i, j, (int)queries.size()});
        }
    }

    // クエリをブロックごとにソート
    sort(queries.begin(), queries.end(), compare);

    vector<long long> results(queries.size());
    unordered_map<int, int> count;
    int distinct_count = 0;
    int currL = 0, currR = -1;

    // 各クエリを処理
    for (Query q : queries) {
        int L = q.L;
        int R = q.R;

        // 現在の範囲を [L, R] に調整
        while (currR < R) {
            currR++;
            add(A[currR], count, distinct_count);
        }
        while (currR > R) {
            remove(A[currR], count, distinct_count);
            currR--;
        }
        while (currL < L) {
            remove(A[currL], count, distinct_count);
            currL++;
        }
        while (currL > L) {
            currL--;
            add(A[currL], count, distinct_count);
        }

        // 現在の範囲 [L, R] に対する結果を保存
        results[q.idx] = distinct_count;
    }

    // 最終結果を出力
    long long final_result = 0;
    for (long long res : results) {
        final_result += res;
    }

    cout << final_result << endl;

    return 0;
}