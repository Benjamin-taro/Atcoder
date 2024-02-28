#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::findを使用するために必要
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

auto solve(const std::vector<int64_t> &P, const std::vector<int64_t> &A, const std::vector<int64_t> &B) {
    vector<int64_t> results;
    for (size_t i = 0; i < A.size(); ++i) {
        auto posA = find(ALL(P), A[i]) - P.begin();
        auto posB = find(ALL(P), B[i]) - P.begin();
        if (posA < posB) {
            results.push_back(A[i]);
        } else {
            results.push_back(B[i]);
        }
    }
    return results;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, Q;
    std::cin >> N;
    std::vector<int64_t> P(N);
    REP(i, N) {
        std::cin >> P[i];
    }
    std::cin >> Q;
    std::vector<int64_t> A(Q), B(Q);
    REP(i, Q) {
        std::cin >> A[i] >> B[i];
    }

    auto results = solve(P, A, B);
    for (auto &result : results) {
        std::cout << result << '\n';
    }
    return 0;
}
