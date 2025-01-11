#include <bits/stdc++.h>
using namespace std;

// Fenwick (Binary Indexed) Tree for counting how many T_k >= i
// We will store +1 at index T_k, and to find how many are >= i
// we do sumFenwicks(M) - sumFenwicks(i-1).

struct Fenwick {
    int n;
    vector<int> fenw;
    Fenwick(int n) : n(n), fenw(n+1, 0) {}
    
    void update(int i, int delta) {
        for (; i <= n; i += i & -i) {
            fenw[i] += delta;
        }
    }
    
    int query(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i) {
            s += fenw[i];
        }
        return s;
    }
    
    // query in [l..r]
    int rangeQuery(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    
    // We need an upper bound for T_i = i + S_i.
    // S_i can be as large as A[i] + (i-1).
    // So T_i can be up to i + A[i] + (i-1) ~ 2*i + 500000.
    // That is at most ~ 2*N + 500000.  We'll pick a Fenwicks array
    // of that size safely.
    const int MAXT = 2*N + 500000 + 10;
    
    Fenwick fenw(MAXT);
    vector<long long> S(N+1, 0);

    for(int i = 1; i <= N; i++){
        // G_i = number of k < i with i <= T_k
        // That is how many T_k are >= i.
        // so G_i = fenw.rangeQuery(i, MAXT).
        long long Gi = fenw.rangeQuery(i, MAXT);
        
        // Now S_i = A_i + G_i
        S[i] = A[i] + Gi;
        
        // T_i = i + S[i]. Store +1 in Fenwicks at T_i.
        long long Ti = i + S[i];
        // Must cast Ti to int if we use it as index. It's guaranteed
        // to be <= MAXT in the problem constraints.
        fenw.update((int)Ti, 1);
    }
    
    // Now compute final stones after N years:
    // Fi = max(0, S_i - (N - i))
    // Because from year i+1..N, up to (N-i) gifts might be forced out.
    for(int i = 1; i <= N; i++){
        long long giveAway = (long long)(N - i); 
        long long remain = S[i] - min(S[i], giveAway);
        cout << remain << (i == N ? '\n' : ' ');
    }
    return 0;
}
