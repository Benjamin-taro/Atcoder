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
bool checker(int i, int64_t K, const std::vector<int64_t> &A, const std::vector<int64_t> &B, int64_t last_value) {
    if(i == 0) return true; // Base case: If we've checked all elements, the sequence is valid.

    // Check if A[i-1] can be used for the current position
    if(abs(A[i-1] - last_value) <= K) {
        if(checker(i-1, K, A, B, A[i-1])) return true;
    }

    // Check if B[i-1] can be used for the current position
    if(abs(B[i-1] - last_value) <= K) {
        if(checker(i-1, K, A, B, B[i-1])) return true;
    }

    return false; // If neither A[i-1] nor B[i-1] can be used, the sequence is invalid.
}

bool solve(int N, int64_t K, const std::vector<int64_t> &A, const std::vector<int64_t> &B) {
    // We start by trying both possible starting values
    if(checker(N-1, K, A, B, A[N-1])) return true;
    if(checker(N-1, K, A, B, B[N-1])) return true;
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    int64_t K;
    std::cin >> N >> K; // Correct the input order for N and K
    std::vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }
    auto ans = solve(N, K, A, B);
    std::cout << (ans ? YES : NO) << endl;
    return 0;
}