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

auto solve(int64_t N, int64_t Q, string S, vector<int64_t> t, vector<int64_t> x) {
    int64_t offset = 0; // 文字列の回転状態を表すオフセット
    for(int64_t i = 0; i < Q; ++i) {
        if(t[i] == 1) {
            // オフセットを更新
            offset = (offset + x[i]) % N;
        } else {
            // 実際の文字の位置を計算し、出力
            int64_t actualIndex = (N + x[i] - offset - 1) % N;
            cout << S[actualIndex] << '\n';
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t N, Q;
    cin >> N >> Q >> ws;
    string S;
    cin >> S;
    vector<int64_t> t(Q), x(Q);
    for(int i = 0; i < Q; ++i) {
        cin >> t[i] >> x[i];
    }
    solve(N, Q, S, t, x);
    return 0;
}
