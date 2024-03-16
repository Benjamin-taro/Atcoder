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

const string YES = "Yes";
const string NO = "No";

bool heal(int64_t xp, int64_t yp, unordered_map<int64_t, unordered_map<int64_t, bool>> &Heal) {
    // Check if there is a healing item at the current position and if it has not been consumed yet.
    if (Heal.count(xp) > 0 && Heal[xp].count(yp) > 0 && Heal[xp][yp]) {
        // Consume the healing item.
        Heal[xp][yp] = false;
        return true;
    }
    return false;
}

bool solve(int64_t N, int M, int64_t H, int64_t K, const string &S, vector<pair<int64_t, int64_t>> &items) {
    int64_t HP = H, xp = 0, yp = 0;
    unordered_map<int64_t, unordered_map<int64_t, bool>> Heal;
    for (const auto &item : items) {
        Heal[item.first][item.second] = true;
    }

    for (char move : S) {
        if (move == 'R') xp++;
        if (move == 'L') xp--;
        if (move == 'U') yp++;
        if (move == 'D') yp--;
        // Check for healing item before checking if HP is below zero.
        if (heal(xp, yp, Heal) && HP < K) {
            HP = K;
        }
        HP--; // Consume health after moving and healing.
        if (HP < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Read the inputs.
    int64_t N, H, K;
    int M;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    vector<pair<int64_t, int64_t>> items(M);
    for (int i = 0; i < M; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    // Solve the problem.
    bool canComplete = solve(N, M, H, K, S, items);

    // Output the result.
    cout << (canComplete ? YES : NO) << endl;

    return 0;
}
