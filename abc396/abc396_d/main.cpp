#include <iostream>
#include <vector>
#include <limits>
#include <cstdint>
#include <algorithm>
using namespace std;

int64_t n, m;
vector<vector<pair<int64_t, int64_t>>> paths;
int64_t ans = numeric_limits<int64_t>::max();
vector<bool> visited;

void dfs(int64_t cur_posi, int64_t xor_sum) {
    if (cur_posi == n - 1) {
        ans = min(ans, xor_sum);
        return;
    }
    visited[cur_posi] = true;
    for (const auto& [u, w] : paths[cur_posi]) {
        if (visited[u]) continue;
        dfs(u, xor_sum ^ w);
    }
    visited[cur_posi] = false; // バックトラック
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    paths.resize(n);   // グローバル変数 paths のサイズを n に調整
    visited.resize(n, false);
    
    for (int i = 0; i < m; ++i) {
        int64_t u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        paths[u].emplace_back(v, w);
        paths[v].emplace_back(u, w);
    }
    
    dfs(0, 0);
    cout << (ans == numeric_limits<int64_t>::max() ? -1 : ans) << "\n";
    return 0;
}
