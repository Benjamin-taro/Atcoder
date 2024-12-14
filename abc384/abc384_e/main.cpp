#include <bits/stdc++.h>
using namespace std;

using P = pair<long long, pair<int,int>>;

static long long S[500][500];
static bool vis[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, x;
    cin >> h >> w >> x;

    int p, q;
    cin >> p >> q;
    --p, --q; // 0-based indexing

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> S[i][j];
        }
    }

    long long s_strength = S[p][q];
    vis[p][q] = true;

    priority_queue<P, vector<P>, greater<>> pq;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    // Push initial neighbors
    for (int i = 0; i < 4; ++i) {
        int nx = p + dx[i];
        int ny = q + dy[i];
        if (nx >= 0 && ny >= 0 && nx < h && ny < w && !vis[nx][ny]) {
            vis[nx][ny] = true; // Mark visited before pushing
            pq.push({S[nx][ny], {nx, ny}});
        }
    }

    while (!pq.empty()) {
        auto [cell_value, position] = pq.top();
        pq.pop();
        auto [cx, cy] = position;

        __int128 val = cell_value;
        if (val * x < s_strength) {
            s_strength += cell_value;

            // Add new neighbors
            for (int i = 0; i < 4; ++i) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx >= 0 && ny >= 0 && nx < h && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({S[nx][ny], {nx, ny}});
                }
            }
        }
    }

    cout << s_strength << "\n";
    return 0;
}
