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


// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t N;
    std::string S;
    int64_t Q;
    std::cin >> N;
    cin >> S;
    cin >> Q;
    std::vector<int64_t> T(Q), A(Q), B(Q);
    REP (i, Q) {
        std::cin >> T[i] >> A[i] >> B[i];
    }
    int64_t offset=0;
    REP(i, Q){
        if(T[i] == 1){
            int64_t as, bs;
            as = S[A[i]-1];
            bs = S[B[i]-1];
            S[A[i]-1] = as;
            S[B[i]-1] = bs;         
        }
        else{
            S = S[-N:] + S[N:];
        }
    }
    std::cout << S << '\n';
    return 0;
}