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
    std::string S;
    std::cin >> S;
    int64_t ans = 0;
    REP(num, 10000){
        vector<int64_t> a(10);
        int64_t x = num;
        REP(i, 4){
            int d = x%10;
            a[d] = 1;
            x/=10;
        }
        bool ok = true;
        REP(i, 10){
            if(S[i] == 'o' && a[i] != 1) ok=false;
            if(S[i] == 'x' && a[i] != 0) ok=false;
        }
        if (ok) ++ans;
    }
    std::cout << ans << '\n';
    return 0;
}
