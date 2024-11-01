#include <iostream>
#include <vector>
#include <queue>
#include <limits>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> g(N);
    
    // グラフの構築
    for (int i = 0; i < M; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--; b--; // 0-indexed に変換
        g[a].push_back(b);
    }

    const int inf = std::numeric_limits<int>::max();
    std::vector<int> d(N, inf);
    std::queue<int> Q;

    d[0] = 0;
    Q.push(0);

    // BFS
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        
        for (int dst : g[cur]) {
            if (dst == 0) {
                std::cout << d[cur] + 1 << "\n";
                return 0;
            }
            if (d[dst] == inf) {
                d[dst] = d[cur] + 1;
                Q.push(dst);
            }
        }
    }

    // ノード 0 に戻れない場合
    std::cout << -1 << "\n";
    return 0;
}
