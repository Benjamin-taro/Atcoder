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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t N;
    std::string S;
    int64_t Q;

    std::cin >> N >> S >> Q;

    std::vector<int64_t> T(Q), A(Q), B(Q);
    for(int i = 0; i < Q; ++i) {
        std::cin >> T[i] >> A[i] >> B[i];
    }

    int64_t offset = 0; //この前の循環のやつから発想を得たけど、別にそんなに数字とか複札にならなかったからただのフラグでよかった。
    for(int i = 0; i < Q; ++i) {
        if(T[i] == 1){
            // C++だとswapが文字列に対して使える模様。今日のコンテストでも出てきた。先頭が中心から始まるのか先頭から始まるのかでインデックスを調整する。
            std::swap(S[(A[i] - 1 + offset) % (2 * N)], S[(B[i] - 1 + offset) % (2 * N)]);
        }
        else {
            // Instead of swapping halves, just keep track of the offset
            //こんな複雑に書かなくてよかったかもシリーズ。0かNかで良い。ここは数字にすると計算にそのまま使えるという利点はあるかもしれない。
            offset = (offset + N) % (2 * N); // This toggles between 0 and N
        }
    }

    // Apply the final offset to adjust the string if needed
    //結局0かNしかoffsetは取り得ないのだが、Nの時はS自体の前後を入れ替えなきゃいけないので入れ替えてあげる。Pythonとは違ってこれはsubstrってやつがある。
    if(offset != 0) {
        S = S.substr(N) + S.substr(0, N);
    }

    std::cout << S << '\n';

    return 0;
}
