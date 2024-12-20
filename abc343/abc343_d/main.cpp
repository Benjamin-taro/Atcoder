#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;


//auto solve(int64_t N, int T, const std::vector<int64_t> &A, const std::vector<int64_t> &B) {

    //for(int i = 0; i < T; i++){
        
    //}
//}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t N;
    int T;
    cin >> N >> T;
    vector<int64_t> C(N, 0);
    map<int64_t, int> valueCounts; // 各値の出現回数を追跡
    int uniqueValueCount = 0; // ユニークな値の数

    // 初期状態のユニークな値の数を計算
    valueCounts[0] = N; // 初期値0がN個ある
    uniqueValueCount = 1; // 初期状態では0のみがユニークな値

    for (int i = 0; i < T; ++i) {
        int64_t A, B;
        cin >> A >> B;
        A--; // 0-indexed に調整

        // 更新前の値の出現回数を減らす
        if (--valueCounts[C[A]] == 0) {
            valueCounts.erase(C[A]);
            uniqueValueCount--;
        }

        C[A] += B;

        // 更新後の値の出現回数を増やす
        if (valueCounts[C[A]]++ == 0) {
            uniqueValueCount++;
        }

        cout << uniqueValueCount << '\n';
    }

    return 0;
}
