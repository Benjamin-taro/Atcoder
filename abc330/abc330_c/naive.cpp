#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

constexpr int64_t MOD = 998244353;
int64_t solve(int64_t D) {
    int64_t temp = 1000000000000;
    for(int x = 0; x * x <= D; x++){
        int64_t y = sqrt(D-x*x);
        for(int i = -2; i <=2; i++){
            if(y+i >= 0 && y+i <= sqrt(D)){
                temp = min(abs(x*x + (y+i)*(y+i) - D), temp);
            }

        }
    }
    return temp;
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t D;
    std::cin >> D;
    auto ans = solve(D);
    std::cout << ans << '\n';
    return 0;
}
