#include <iostream>
#include <string>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;


int64_t solve(int H, int64_t W, const std::vector<std::string> &S) {
    int64_t x, y;
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    std::vector<std::string> sen;
    for(int i = 0; i<H; i++){
        for(int j = 0; j<H; j++){
            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                // 新しい位置がグリッド内かつ未訪問でセンサーが存在する場合に探索を続ける
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && grid[nx][ny] == '#' && !visited[nx][ny]) {
                    dfs(nx, ny, grid);
            }
        
        }
    }
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int H;
    int64_t W;
    std::cin >> H;
    std::vector<std::string> S(H);
    std::cin >> W;
    REP (i, H) {
        std::cin >> S[i];
    }
    auto ans = solve(H, W, S);
    std::cout << ans << '\n';
    return 0;
}