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
    
    int q;
    std::cin >> q;
    std::multiset<int64_t> S;
    REP(i, q){
        int type;
        std::cin >> type;
        if(type == 1){
            int64_t x;
            std::cin >> x;
            S.insert(x);
        }
        else if(type == 2){
            int64_t x, c;
            std::cin >> x >> c;
            while(c-- && S.find(x) != S.end()) {
                S.erase(S.find(x));
            }
        }
        else if(type == 3){
            if(!S.empty()){
                std::cout << *S.rbegin() - *S.begin() << '\n';
            }
        }
    }

    return 0;
}