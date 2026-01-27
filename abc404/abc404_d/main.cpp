#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, m;
    cin >> n >> m;

    vector<int64_t> cost(n);
    for (int i = 0; i < (int)n; i++) cin >> cost[i];

    // 動物ごとに「見られる動物園集合」を bitmask で持つ
    vector<int> animalMask(m, 0);

    // ここは m 回（動物の行が m 行）
    for (int a = 0; a < (int)m; a++) {
        int k; cin >> k;
        int mask = 0;
        for (int j = 0; j < k; j++) {
            int z; cin >> z; // 動物園番号(1-indexed)
            --z;
            mask |= (1 << z);
        }
        animalMask[a] = mask;
    }

    // 3^n
    int64_t S = 1;
    for (int i = 0; i < (int)n; i++) S *= 3;

    const int64_t INF = (1LL<<62);
    int64_t ans = INF;

    for (int64_t state = 0; state < S; state++) {
        int64_t tmp = state;

        // visit[i] = 0/1/2
        int visit[10] = {};
        int64_t totalCost = 0;

        for (int i = 0; i < (int)n; i++) {
            visit[i] = (int)(tmp % 3);
            tmp /= 3;
            totalCost += (int64_t)visit[i] * cost[i];
        }
        if (totalCost >= ans) continue; // 枝刈り

        bool ok = true;
        for (int a = 0; a < (int)m; a++) {
            int mask = animalMask[a];
            int cnt = 0;
            for (int i = 0; i < (int)n; i++) {
                if (mask & (1 << i)) cnt += visit[i];
            }
            if (cnt < 2) { ok = false; break; }
        }

        if (ok) ans = totalCost;
    }

    cout << ans << "\n";
    return 0;
}
