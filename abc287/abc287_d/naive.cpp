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
#include <stack>
#include <unordered_map>
#include <type_traits> // For std::is_floating_point
#include <cmath> // For std::ceil
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
//文字配列の二次元配列みたいなやつを回転させる。
vector<string> rotate90(const vector<string>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<string> rotated(m, string(n, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }
    return rotated;
}



const string YES = "Yes";
const string NO = "No";

int solve(const string& S, const string& T) {
    for(int i = 0; i <= int(S.size()) - int(T.size()); ++i) {
        bool match = true;
        for(int j = 0; j < T.size(); ++j) {
            if(S[i+j] != '?' && S[i+j] != T[j]) {
                match = false;
                break;
            }
        }
        if(match) cout << YES << '\n';
        else cout << NO << '\n';
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S, T;
    cin >> S >> T;
    solve(S,T);

    return 0;
}
