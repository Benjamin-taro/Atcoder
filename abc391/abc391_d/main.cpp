#include <bits/stdc++.h>
using namespace std;

static const long long INF = LLONG_MAX;

// メイン
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W; // N=ブロック数, W=列数
    cin >> N >> W;

    // 列ごとに「(y座標, ブロックID)」を入れる
    vector<vector<pair<long long,int>>> col(W+1);
    for(int i = 1; i <= N; i++){
        long long x, y;
        cin >> x >> y;
        // 入力例外(範囲外)はここでは扱わない想定
        col[x].push_back({y, i});
    }

    // 列ごとに y座標昇順でソート
    for(int c = 1; c <= W; c++){
        sort(col[c].begin(), col[c].end(),
             [](auto &a, auto &b){return a.first < b.first;});
    }

    // 各列のブロック数の最小 => これが「全列で揃う行数(minCount)」
    int minCount = INT_MAX;
    for(int c = 1; c <= W; c++){
        int sz = (int)col[c].size();
        minCount = min(minCount, sz);
    }

    // もし minCount=0 なら、一度も全列は揃わない => すべて消えない(∞)
    // 以降の計算はスキップしてクエリ処理に進んでOK
    // ただし T は minCount+1=1 要素になるが使わない。
    // コード上は minCount=0 のときだけ特別処理してもいいし、そのままでもいい。

    // rankごとに (yの最大値) を求める
    // rank = 1..minCount
    vector<long long> max_y_for_rank(minCount+1, 0LL);
    for(int c = 1; c <= W; c++){
        // 下から k番目 => ソート結果の index=k-1
        for(int k = 0; k < (int)col[c].size(); k++){
            int rank = k + 1;
            if(rank <= minCount){
                long long y = col[c][k].first;
                max_y_for_rank[rank] = max(max_y_for_rank[rank], y);
            }
        }
    }

    // 各 k行目が消える時刻 T[k] (1-based)
    // T[0] = 0 とし、
    //   T[k] = T[k-1] + max(1, max_y_for_rank[k] - (k-1))
    // にしている (問題仕様によって +1する形にすることも)
    vector<long long> T(minCount+1, 0LL);
    for(int k = 1; k <= minCount; k++){
        // 「ブロックが落ちるのに必要な時間」を計算:
        //   = max_y_for_rank[k] - (k-1)
        //   (下から(k-1)行分がすでに埋まっている想定、そこに落ちるまで)
        // 負になってしまう可能性があるなら max(0, ...) にする等
        long long fallTime = max_y_for_rank[k] - (k - 1);

        // “最低でも1はかかる” ならこうする (問題によっては0でいい場合あり):
        if(fallTime < 1) fallTime = 1;

        T[k] = T[k-1] + fallTime;
    }

    // 各ブロックの消滅時刻 rm_time[id]
    // 初期値は INF (消えない)
    vector<long long> rm_time(N+1, INF);

    // rank <= minCount のブロックだけ T[rank] で消える
    for(int c = 1; c <= W; c++){
        for(int k = 0; k < (int)col[c].size(); k++){
            int rank = k+1;
            int id   = col[c][k].second;
            if(rank <= minCount){
                // 全列がその rank 目でそろう => 時刻 T[rank] で消える
                rm_time[id] = T[rank];
            }
        }
    }

    // クエリ処理
    int Q; 
    cin >> Q;
    while(Q--){
        long long t; // 質問時刻
        int a;       // ブロックID
        cin >> t >> a;
        // 時刻 (t + 0.5) にブロック a が存在するかどうか
        // 消滅時刻 rm_time[a] と比較し、 t < rm_time[a] ならまだ残っている
        if(t < rm_time[a]){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
