#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <atcoder/dsu>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;


int main() {
    using namespace std;
    unsigned N;
    cin >> N;
    // 頂点 1 を取り除いた森について、
    // union find で連結成分を管理
    atcoder::dsu forest(N);
    for (unsigned i = 1; i < N; ++i) {
        unsigned u, v;
        cin >> u >> v;
        if (u != 1) // 頂点 1 に接続する辺でなければ
            forest.merge(u - 1, v - 1); // 辺を追加
    }
    // N から最大の連結成分のサイズを引いたものが答え
    cout << N - ranges::max(forest.groups() | views::transform([](auto &&g) { return size(g); })) << endl;
    return 0;
}
