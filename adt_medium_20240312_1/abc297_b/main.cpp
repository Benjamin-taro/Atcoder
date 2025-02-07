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

const std::string YES = "Yes";
const std::string NO = "No";
bool solve(std::string S) {
    vector<int64_t> B;
    vector<int64_t> K;
    vector<int64_t> R;
    for(int64_t i=0; i<S.length(); i++){
        if(S[i] == 'B'){
            B.push_back(i);
        }
        if(S[i] == 'R'){
            R.push_back(i);
        }
        if(S[i] == 'K'){
            K.push_back(i);
        }
    }
    if((((B[0]+1)%2) == 1 && ((B[1]+1)%2) == 0) || (((B[0]+1)%2) == 0 && ((B[1]+1)%2) == 1)){
        if(R[0]<K[0] && K[0]<R[1]){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

    return false;

}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string S;
    std::cin >> S;
    auto ans = solve(S);
    std::cout << (ans ? YES : NO) << '\n';
    return 0;
}
