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



const std::string YES = "Yes";
const std::string NO = "No";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<vector<int64_t>> max_energy(h, vector<int64_t>(w, 0));
    pair<int64_t, int64_t> start, goal;
    REP(i, h) {
        REP(j, w) {
            cin >> a[i][j];
            if(a[i][j] == 'S') {
                start = {i, j};
            } else if(a[i][j] == 'T') {
                goal = {i, j};
            }
        }
    }
    int64_t n;
    cin >> n;
    vector<tuple<int64_t, int64_t, int64_t>> medicines(n);
    REP (i, n) {
        int64_t r, c, e;
        cin >> r >> c >> e;
        medicines[i] = make_tuple(r-1, c-1, e); // Adjusting for 0-based indexing
    }

    // Use a priority queue to always pick the path with the most energy.
    auto cmp = [](const tuple<int64_t, int64_t, int64_t>& left, const tuple<int64_t, int64_t, int64_t>& right) {
        return get<0>(left) < get<0>(right); // Compare based on energy, reversed to make it max-heap
    };
    priority_queue<tuple<int64_t, int64_t, int64_t>, vector<tuple<int64_t, int64_t, int64_t>>, decltype(cmp)> q(cmp);

    // Start with the energy from the medicine at the start, if any.
    int64_t start_energy = 0;
    for (auto& med : medicines) {
        if (get<0>(med) == start.first && get<1>(med) == start.second) {
            start_energy = get<2>(med);
            get<2>(med) = -1; // Mark the medicine as used.
            break;
        }
    }

    q.push(make_tuple(start_energy, start.first, start.second)); // Push the starting position with its energy.

    const vector<pair<int64_t, int64_t>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool can_reach = false;

    while (!q.empty()) {
        auto [energy, x, y] = q.top();
        q.pop();

        if (make_pair(x, y) == goal) {
            can_reach = true;
            break;
        }

        if (energy == 0) continue; // Cannot move further if energy is 0.

        for (auto& d : directions) {
            int64_t nx = x + d.first;
            int64_t ny = y + d.second;
            
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && a[nx][ny] != '#' && energy > max_energy[nx][ny]) {
                max_energy[nx][ny] = energy; // Update the energy level of the cell.

                // Check for medicines at this cell.
                int64_t new_energy = energy - 1;
                for (auto& med : medicines) {
                    if (get<2>(med) != -1 && get<0>(med) == nx && get<1>(med) == ny) {
                        new_energy = max(new_energy, get<2>(med)); // Use the medicine.
                        get<2>(med) = -1; // Mark the medicine as used.
                        break; // Only use one medicine at a time.
                    }
                }

                q.push(make_tuple(new_energy, nx, ny)); // Add the new position with updated energy.
            }
        }
    }

    cout << (can_reach ? YES : NO) << '\n';
    return 0;
}
