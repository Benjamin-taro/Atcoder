#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <limits>
#include <iomanip>
using namespace std;

#define INF numeric_limits<long double>::max()

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long double S, T;
    cin >> N;
    vector<long double> A(N), B(N), C(N), D(N);
    cin >> S >> T;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<long double> segtimes(N);
    for (int i = 0; i < N; i++) {
        segtimes[i] = hypot(C[i] - A[i], D[i] - B[i]) / T;
    }

    long double ans = INF;

    auto dfs = [&](auto&& self, int parent, int parentStart, long double totaltime, int count, vector<int>& visited) -> void {
        if (count == N) {
            ans = min(ans, totaltime);
            return;
        }

        long double parentx = 0, parenty = 0;
        if (parentStart == 0) {
            parentx = A[parent];
            parenty = B[parent];
        } else if (parentStart == 1) {
            parentx = C[parent];
            parenty = D[parent];
        }

        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;

            visited[i] = 1;

            long double travel0 = hypot(A[i] - parentx, B[i] - parenty) / S;
            long double travel1 = hypot(C[i] - parentx, D[i] - parenty) / S;

            // travel0 と travel1 の合計時間を慎重に計算
            long double newTime0 = totaltime + travel0 + segtimes[i];
            long double newTime1 = totaltime + travel1 + segtimes[i];

            // 両方のケースを探索
            self(self, i, 0, newTime0, count + 1, visited);
            self(self, i, 1, newTime1, count + 1, visited);

            // バックトラッキング - 訪問状態をリセット
            visited[i] = 0;
        }
    };

    vector<int> vis(N, 0);
    dfs(dfs, -1, -1, 0.0, 0, vis);

    cout << fixed << setprecision(28) << ans << endl;

    return 0;
}
