#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint> // For int64_t
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))

using namespace std;

const string YES = "Yes";
const string NO = "No";

vector<string> solve(int N, vector<int64_t>& A, int M, const vector<int64_t>& B, int L, const vector<int64_t>& C, int Q, const vector<int64_t>& X) {
    vector<string> answers;
    // BとCから可能な全ての和を計算します。
    vector<int64_t> BC;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < L; ++j) {
            BC.push_back(B[i] + C[j]);
        }
    }
    // 和のリストをソートします。
    sort(BC.begin(), BC.end());
    // 重複を削除します。
    //BC.erase(unique(BC.begin(), BC.end()), BC.end());
    sort(A.begin(), A.end());
    for (auto x : X) {
        bool found = false;
        for (auto a : A) {
            if (found) break; // 既に見つかっている場合はループを抜けます。
            if (a > x) break; // aがxより大きい場合、これ以上探す必要はありません。
            int64_t remain = x - a;
            // 二分探索でB+Cのリストにremainが存在するか確認します。
            found = binary_search(BC.begin(), BC.end(), remain);
        }
        answers.push_back(found ? YES : NO);
    }

    return answers;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, L, Q;
    cin >> N;
    vector<int64_t> A(N);
    for (auto& a : A) cin >> a;
    cin >> M;
    vector<int64_t> B(M);
    for (auto& b : B) cin >> b;
    cin >> L;
    vector<int64_t> C(L);
    for (auto& c : C) cin >> c;
    cin >> Q;
    vector<int64_t> X(Q);
    for (auto& x : X) cin >> x;

    auto answers = solve(N, A, M, B, L, C, Q, X);
    for (const auto& answer : answers) {
        cout << answer << '\n';
    }
    return 0;
}