#include <iostream>
#include <string>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;


//auto solve(int64_t M, int64_t D, int64_t y, int64_t m, int64_t d) {
    

//}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t M, D, y, m, d;
    std::cin >> M >> D >> y >> m >> d;
    if (d == D){
        d = 1;
        if (m != M){
            m += 1;
        }
        else{
            m = 1;
            y +=1;
        }
    }
    else{
        d += 1;
    }
    //auto ans = solve(M, D, y, m, d);
    std::cout << y << ' ' << m << ' ' << d << '\n';
    return 0;
}
