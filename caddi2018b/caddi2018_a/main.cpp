#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, P;
    cin >> N >> P;

    // 1. P を素因数分解
    //    試し割り用に sqrt(P) までで十分
    map<long long, long long> primeExp;
    {
        long long tmp = P;
        for (long long p = 2; p * p <= tmp; p++) {
            while (tmp % p == 0) {
                primeExp[p]++;
                tmp /= p;
            }
        }
        if (tmp > 1) {
            // 残った tmp が 1 でなければ、それが素数
            primeExp[tmp]++;
        }
    }

    // 2. e_p / N の切り捨てを各素数 p について求める
    long long ans = 1;
    for (auto &kv : primeExp) {
        long long p = kv.first;
        long long e = kv.second;
        // floor(e / N) の回数だけ p を掛ける
        long long times = e / N;
        for (int i = 0; i < times; i++) {
            ans *= p; // オーバーフローには注意（本問題では最大 10^12 の範囲ならOKかと）
        }
    }

    cout << ans << "\n";
    return 0;
}
