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

// Calculate n factorial
int64_t factorial(int n) {
    int64_t result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Calculate n choose k using factorial
int64_t nChooseK(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// This function calculates the number of valid PINs based on the input string.
int64_t solve(const std::string& S) {
    int clear = 0; // Count of 'o'
    int unclear = 0; // Count of '?'

    // Count the number of 'o' and '?' in the input string
    for (char c : S) {
        if (c == 'o') {
            ++clear;
        } else if (c == '?') {
            ++unclear;
        }
    }

    // If the number of certain digits is greater than 4, or there are no digits to choose from, return 0.
    if (clear > 4 || clear + unclear == 0) {
        return 0;
    }

    // Calculate the number of ways to choose the remaining digits from the '?' characters
    // and calculate the permutations for the chosen digits.
    int64_t answer = 0;
    for (int i = clear; i <= min(4, clear + unclear); ++i) {
        int64_t permutations = factorial(i); // Permutations of the chosen digits
        int64_t combinations = nChooseK(clear + unclear, i); // Combinations to choose i digits
        answer += combinations * permutations * (int64_t)pow(10 - i, 4 - i);
    }

    return answer;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    std::cin >> S;
    auto ans = solve(S);
    std::cout << ans << '\n';
    return 0;
}

