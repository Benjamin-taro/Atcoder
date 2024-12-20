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

const std::string YES = "Yes";
const std::string NO = "No";
bool solve(int N, int M, const std::vector<int64_t> &A, const std::vector<int64_t> &B, const std::vector<int64_t> &C, const std::vector<int64_t> &D) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N;
    std::vector<int64_t> A(N), B(N);
    std::cin >> M;
    std::vector<int64_t> C(M), D(M);
    REP (i, N) {
        std::cin >> A[i];
    }
    REP (i, N) {
        std::cin >> B[i];
    }
    REP (i, M) {
        std::cin >> C[i];
    }
    REP (i, M) {
        std::cin >> D[i];
    }
    auto ans = solve(N, M, A, B, C, D);
    std::cout << (ans ? YES : NO) << '\n';
    return 0;
}
