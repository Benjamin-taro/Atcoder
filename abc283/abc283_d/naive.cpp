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

bool solve(const std::string& S) {
    int balance = 0; // Track the balance of parentheses
    std::set<char> seenChars; // Track seen characters outside of parentheses
    std::set<char> tempChars; // Temporarily track characters inside current parentheses

    for (char ch : S) {
        if (ch == '(') {
            balance++;
            tempChars.clear(); // Clear temporary characters for new parentheses
        } else if (ch == ')') {
            if (balance <= 0) return false; // More closing than opening parentheses
            balance--;
            seenChars.insert(tempChars.begin(), tempChars.end()); // Merge tempChars into seenChars
            tempChars.clear();
        } else {
            if (balance == 0) { // Outside of parentheses
                if (!seenChars.insert(ch).second) return false; // Character already seen outside
            } else { // Inside parentheses
                if (!tempChars.insert(ch).second) return false; // Character already seen inside current parentheses
            }
        }
    }

    return balance == 0; // Ensure all parentheses are closed
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    std::cin >> S;
    bool ans = solve(S);
    std::cout << (ans ? YES : NO) << '\n';
    return 0;
}
