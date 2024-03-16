#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint> // For int64_t
using namespace std;

const std::string YES = "Yes";
const std::string NO = "No";

auto solve(int N, const std::vector<int64_t> &A, int M, const std::vector<int64_t> &B, int L, const std::vector<int64_t> &C, int Q, const std::vector<int64_t> &X) {
    std::vector<string> answers;
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    std::sort(C.begin(), C.end());

    for (const auto &x : X) {
        bool found = false;
        for (auto a : A) {
            if (a > x) break; // If a is already larger than x, stop searching.
            int64_t remain = x - a;
            for (auto b : B) {
                if (b > remain) break; // If b is larger than remain, no need to continue in this loop.
                int64_t remain_bc = remain - b;
                // Use binary search for C as it's sorted, which is more efficient.
                if (binary_search(C.begin(), C.end(), remain_bc)) {
                    found = true;
                    break; // Found a valid combination.
                }
            }
            if (found) break; // If found a combination, no need to continue searching.
        }
        answers.push_back(found ? YES : NO);
    }
    return answers;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M, L, Q;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    std::cin >> M;
    std::vector<int64_t> B(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> B[i];
    }
    std::cin >> L;
    std::vector<int64_t> C(L);
    for (int i = 0; i < L; ++i) {
        std::cin >> C[i];
    }
    std::cin >> Q;
    std::vector<int64_t> X(Q);
    for (int i = 0; i < Q; ++i) {
        std::cin >> X[i];
    }
    auto ans = solve(N, A, M, B, L, C, Q, X);
    for (const auto& answer : ans) {
        std::cout << answer << '\n';
    }
    return 0;
}