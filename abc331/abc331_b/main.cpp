#include <iostream>
#include <string>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;


int64_t solve(int64_t N, int64_t S, int64_t M, int64_t L) {
    int64_t temp = 1000000000;
    for(int i = 0; i <=100; i++){
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100; k++){
                if (6*i + 8*j + 12*k >= N){
                    temp = min(temp, i*S+j*M+k*L);
                }
            }        
        }
    }
    return temp;
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t N, S, M, L;
    std::cin >> N >> S >> M >> L;
    auto ans = solve(N, S, M, L);
    std::cout << ans << '\n';
    return 0;
}