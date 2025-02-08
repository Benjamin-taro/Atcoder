#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h1, w1;
    cin >> h1 >> w1;
    vector<vector<int64_t>> a(h1, vector<int64_t>(w1));
    for (int i = 0; i < h1; ++i) {
        for (int j = 0; j < w1; ++j) {
            cin >> a[i][j];
        }
    }

    int h2, w2;
    cin >> h2 >> w2;
    vector<vector<int64_t>> b(h2, vector<int64_t>(w2));
    for (int i = 0; i < h2; ++i) {
        for (int j = 0; j < w2; ++j) {
            cin >> b[i][j];
        }
    }

    bool found = false;

    // 全ての行の組み合わせを試す
    for (int row_mask = 0; row_mask < (1 << h1); ++row_mask) {
        vector<int> selected_rows;
        for (int i = 0; i < h1; ++i) {
            if (row_mask & (1 << i)) selected_rows.push_back(i);  // ビットが立っている行を選ぶ
        }
        if (selected_rows.size() != h2) continue;  // 選んだ行がh2と一致しない場合はスキップ

        // 全ての列の組み合わせを試す
        for (int col_mask = 0; col_mask < (1 << w1); ++col_mask) {
            vector<int> selected_cols;
            for (int j = 0; j < w1; ++j) {
                if (col_mask & (1 << j)) selected_cols.push_back(j);  // ビットが立っている列を選ぶ
            }
            if (selected_cols.size() != w2) continue;  // 選んだ列がw2と一致しない場合はスキップ

            // 選んだ行と列で部分行列を作り、Bと比較
            bool match = true;
            for (int i = 0; i < h2 && match; ++i) {
                for (int j = 0; j < w2; ++j) {
                    if (a[selected_rows[i]][selected_cols[j]] != b[i][j]) {
                        match = false;
                        break;
                    }
                }
            }

            if (match) {
                found = true;
                break;  // 一致する部分行列が見つかったらループを抜ける
            }
        }

        if (found) break;  // 一致する部分行列が見つかったら外側のループも抜ける
    }

    cout << (found ? YES : NO) << '\n';
    return 0;
}
