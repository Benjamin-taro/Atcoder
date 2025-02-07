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
#include <unordered_map>
#include <type_traits> // For std::is_floating_point
#include <cmath> // For std::ceil
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;


int64_t solve(int N, int M, int64_t K, const std::vector<int64_t> &A, const std::vector<int64_t> &B, const std::vector<int64_t> &X) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    int64_t K;
    std::cin >> N;
    std::vector<int64_t> X(N);
    std::cin >> M;
    std::vector<int64_t> A(M), B(M);
    std::cin >> K;
    REP (i, M) {
        std::cin >> A[i] >> B[i];
    }
    REP (i, N) {
        std::cin >> X[i];
    }
    auto ans = solve(N, M, K, A, B, X);
    std::cout << ans << '\n';
    return 0;
}
