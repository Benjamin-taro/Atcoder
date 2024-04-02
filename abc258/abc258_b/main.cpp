#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;



int64_t solve(int64_t N, vector<string> A) {
    const int di [] = {-1, -1, -1, 0, 0, 1 , 1, 1};
    const int dj [] = {-1, 0, 1, -1, 1, -1 , 0, 1};
    int64_t ans = 0;
    REP(i, N){
        REP(j, N){
            REP(k, 8){
                int64_t I = i, J = j;
                int64_t x = 0;
                REP(l, N){
                    x = x * 10 + A[I][J] - '0';
                    I += di[k];
                    J += dj[k];
                    I = (I + N) % N;
                    J = (J + N) % N;
                }
                ans = max(ans, x);
            }
            
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t N;
    std::cin >> N;
    std::vector<string> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    auto ans = solve(N, A);
    std::cout << ans << '\n';
    return 0;
}
