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


#include <iostream>
#include <vector>
#include <algorithm>

int N, H, W;
std::vector<int> A, B;

bool fit_tiles(int x, int y, std::vector<std::vector<bool>>& grid, std::vector<bool>& used) {
    if (y == W) { // 次の行へ
        x++;
        y = 0;
    }
    if (x == H) return true; // 全て埋められた
    if (grid[x][y]) return fit_tiles(x, y + 1, grid, used); // 既に埋まっている場所をスキップ

    for (int i = 0; i < N; ++i) {
        if (used[i]) continue; // 既に使用済みのタイルはスキップ
        // タイルを配置する方向を2通り試す
        for (int rot = 0; rot < 2; ++rot) {
            int width = rot ? B[i] : A[i];
            int height = rot ? A[i] : B[i];
            // タイルがグリッドに収まるかチェック
            if (x + height <= H && y + width <= W) {
                bool ok = true;
                for (int dx = 0; dx < height && ok; ++dx) {
                    for (int dy = 0; dy < width && ok; ++dy) {
                        if (grid[x + dx][y + dy]) ok = false; // 既に埋まっている場所がある
                    }
                }
                if (!ok) continue;
                // タイルを置く
                for (int dx = 0; dx < height; ++dx) {
                    for (int dy = 0; dy < width; ++dy) {
                        grid[x + dx][y + dy] = true;
                    }
                }
                used[i] = true;
                if (fit_tiles(x, y + width, grid, used)) return true; // 次のタイルへ
                // タイルを戻す
                for (int dx = 0; dx < height; ++dx) {
                    for (int dy = 0; dy < width; ++dy) {
                        grid[x + dx][y + dy] = false;
                    }
                }
                used[i] = false;
            }
        }
    }
    return false;
}

int main() {
    std::cin >> N >> H >> W;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i] >> B[i];
    }
    std::vector<std::vector<bool>> grid(H, std::vector<bool>(W, false));
    std::vector<bool> used(N, false);
    if (fit_tiles(0, 0, grid, used)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}
