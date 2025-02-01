#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N, W;
    cin >> N >> W;
    // 各列 (1-indexed) ごとに (y座標, ブロックID) を格納する
    vector<vector<pair<int,int>>> cols(W+1);
    // ブロックの座標（1-indexed）を保存
    vector<int> X(N+1), Ycoord(N+1);
    for (int i = 1; i <= N; i++){
        int x, y;
        cin >> x >> y;
        X[i] = x; 
        Ycoord[i] = y;
        cols[x].push_back({y, i});
    }
 
    // 各列内で y 座標昇順にソートし、ブロックの順位（下から何番目か；1-indexed）を記録する
    vector<int> blockRank(N+1, 0);
    vector<int> colCount(W+1, 0);
    for (int x = 1; x <= W; x++){
        sort(cols[x].begin(), cols[x].end(), [](auto &a, auto &b){
            return a.first < b.first;
        });
        colCount[x] = cols[x].size();
        for (int j = 0; j < (int)cols[x].size(); j++){
            int bid = cols[x][j].second;
            blockRank[bid] = j + 1; // 下から j+1 番目（1-indexed）
        }
    }
 
    // r_star = 各列のブロック数の最小値（＝グローバル削除イベントが起こりうる最大回数）
    int r_star = INT_MAX;
    for (int x = 1; x <= W; x++){
        r_star = min(r_star, colCount[x]);
    }
    if(r_star == INT_MAX) r_star = 0; // もしどこかの列が空なら
 
    // Q 個のクエリに備え、各ランクごとの削除時刻を直接計算する
    // R[j] (0-indexed) は「全列における下から j+1 番目のブロックが削除される時刻」
    // 理論上、1-indexedで第 j 回目の削除時刻は max( y_{x,j} - j + 1 ) なので、
    // 0-indexedに直すと R[j] = max( y_{x,j+1} - j )
    // ※ ただし、削除イベントは前のイベントより必ず 1 だけ後になるように補正する
    vector<int> R(r_star, 0);
    for (int j = 0; j < r_star; j++){
        int candidate = 0;
        for (int x = 1; x <= W; x++){
            // cols[x][j].first は、列 x の下から j+1 番目のブロックの y 座標
            candidate = max(candidate, cols[x][j].first);
        }
        if(j == 0)
            R[j] = candidate;
        else
            R[j] = max(candidate, R[j-1] + 1);
    }
 
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++){
        long long T;
        int A;
        cin >> T >> A;
        int rankA = blockRank[A]; // ブロック A の所属列での順位（1-indexed）
        if(rankA > r_star){
            // その列では削除イベントは r_star 回しか起こらないので、
            // ランクが r_star より大きいブロックは削除されない
            cout << "Yes" << "\n";
        } else {
            int removalTime = R[rankA - 1]; // ブロック A の削除時刻
            // 問題文は「時刻 T+0.5 の状態」を問うているので、
            // 削除イベントは整数時刻に起こるとみなし、T >= removalTime なら既に削除済み
            cout << (T < removalTime ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}
