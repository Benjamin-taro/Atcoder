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
#include <cstring>
#include <iomanip>  // 追加: 出力精度を指定するため
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

// Union-Find データ構造
class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

// 4方向の移動用のベクトル (上, 下, 左, 右)
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool is_valid(int r, int c, int H, int W) {
    return r >= 0 && r < H && c >= 0 && c < W;
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Union-Findの初期化 (グリッドを1次元配列にマッピング)
    UnionFind uf(H * W);

    // 訪問済みのセルを管理するセット
    set<pair<int, int>> visited;

    // 訪問可能セルの数をカウント
    int visited_count = 0;

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--; // 1-indexed -> 0-indexed

        int cell = r * W + c;

        // 初めて訪問する場合、その場所だけを訪問
        if (visited.count({r, c}) == 0) {
            visited.insert({r, c});
            visited_count++;
        } else {
            // すでに訪問していた場合、4方向に向かって未訪問セルを探索
            for (int d = 0; d < 4; ++d) {
                int nr = r, nc = c;
                while (is_valid(nr + dr[d], nc + dc[d], H, W)) {
                    nr += dr[d];
                    nc += dc[d];

                    // 未訪問セルが見つかったら訪問し、探索を終了
                    if (visited.count({nr, nc}) == 0) {
                        visited.insert({nr, nc});
                        visited_count++;
                        int neighbor_cell = nr * W + nc;
                        uf.unite(cell, neighbor_cell);
                        break;
                    }
                }
            }
        }
    }

    // 訪問されていないセルの数を出力
    int total_cells = H * W;
    int unvisited_cells = total_cells - visited_count;
    cout << unvisited_cells << endl;

    return 0;
}