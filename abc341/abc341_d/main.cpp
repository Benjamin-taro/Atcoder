#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

int64 gcdll(int64 a, int64 b){
    while(b){ int64 t=a%b; a=b; b=t; }
    return a;
}

int64 solve(int64 N, int64 M, int64 K){
    int64 g = gcdll(N, M);
    i128 L = (i128)N / g * (i128)M; // lcm (as 128)

    auto count = [&](int64 x)->i128{
        i128 X = x;
        return X / N + X / M - 2 * (X / L);
    };

    // 上限を指数的に伸ばす（安全）
    int64 lo = 1;
    int64 hi = 1;
    while(count(hi) < (i128)K){
        if (hi > (LLONG_MAX / 2)) { hi = LLONG_MAX; break; }
        hi *= 2;
    }

    // 二分探索：count(x) >= K となる最小 x
    while(lo < hi){
        int64 mid = lo + (hi - lo) / 2;
        if(count(mid) >= (i128)K) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M, K;
    cin >> N >> M >> K;
    cout << solve(N, M, K) << "\n";
}
