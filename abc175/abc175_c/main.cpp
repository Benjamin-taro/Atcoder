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


int64_t solve(int64_t X, int64_t K, int64_t D) {
    int64_t distance = abs(X);
    if (distance/D < K){
        if(abs(distance - (distance/D)*D) < abs(distance - ((distance/D)+1)*D)){
            //行き過ぎた時残り何回か？
            if((K - (distance/D)+1)%2 == 1){
                return abs(distance - (distance/D)*D);
            }
            else{
                return abs(distance - ((distance/D)+1)*D);
            }
        }
        else{
            //行き過ぎた時残り何回か？
            if((K - (distance/D))%2 == 1){
                return abs(distance - ((distance/D)+1)*D);
            }
            else{
                return abs(distance - (distance/D)*D);
            }
        }
    }
    else{
        return abs(distance - K*D);
    }

}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t X, K, D;
    std::cin >> X >> K >> D;
    auto ans = solve(X, K, D);
    std::cout << ans << endl;
    return 0;
}