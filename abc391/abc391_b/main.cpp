#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    
    vector<string> T(M);
    for (int i = 0; i < M; ++i) {
        cin >> T[i];
    }
    
    // Iterate over valid top-left positions for M × M submatrix
    for (int i = 0; i <= N - M; ++i) {
        for (int j = 0; j <= N - M; ++j) {
            bool ok = true;
            for (int k = 0; k < M; ++k) {
                for (int l = 0; l < M; ++l) {
                    if (S[i + k][j + l] != T[k][l]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                cout << i + 1 << " " << j + 1 << endl;  // Convert to 1-based indexing
                return 0;
            }
        }
    }
}
