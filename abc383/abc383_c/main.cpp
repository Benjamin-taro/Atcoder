#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// グローバル変数
int H, W;

void bfs(vector<vector<bool>>& covered, const vector<string>& S, int D, const vector<pair<int, int>>& humidifiers) {
    // キューを使用したBFS
    queue<pair<pair<int, int>, int>> q; // {{x, y}, depth}

    // 初期状態をキューに追加
    for (const auto& h : humidifiers) {
        q.push({h, 0});
        covered[h.first][h.second] = true; // 開始地点をカバー済みに
    }

    // 移動方向の定義
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [pos, depth] = q.front();
        q.pop();

        int x = pos.first;
        int y = pos.second;

        if (depth >= D) continue; // 深さ制限

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 範囲外や壁、既にカバー済みのマスはスキップ
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (S[nx][ny] == '#') continue;
            if (covered[nx][ny]) continue;
            if (S[nx][ny] != '.') continue; // '.' のみ探索

            // 新しいマスをカバー済みにしてキューに追加
            covered[nx][ny] = true;
            q.push({{nx, ny}, depth + 1});
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> H >> W; // グローバル変数に格納
    int D;
    cin >> D;

    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    // 加湿器の位置を収集
    vector<pair<int, int>> humidifiers;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'H') {
                humidifiers.push_back({i, j});
            }
        }
    }

    // カバーされるマスを管理（2次元配列）
    vector<vector<bool>> covered(H, vector<bool>(W, false));
    bfs(covered, S, D, humidifiers);

    // カバーされたマス数をカウント
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (covered[i][j]) {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
