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


long long distinct_string_swaps_advanced(const std::string &S) {
    std::unordered_map<char, long long> char_count;
    for (char c : S) {
        ++char_count[c];
    }

    long long n = S.length();
    long long total_swaps = n * (n - 1) / 2;

    // Subtract the swaps that result in duplicates due to multiple occurrences of different characters
    for (const auto &pair1 : char_count) {
        for (const auto &pair2 : char_count) {
            if (pair1.first < pair2.first) {
                total_swaps -= pair1.second * pair2.second;
            }
        }
    }
    
    // Ensure at least one distinct string (the original string itself)
    return std::max(total_swaps, 1LL);
}

int main() {
    std::string S;
    std::cin >> S;
    std::cout << distinct_string_swaps_advanced(S) << std::endl;
    return 0;
}

