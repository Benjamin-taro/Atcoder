#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <array>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <numeric>
#include <assert.h>
#include <unordered_map>
#include <type_traits> // For std::is_floating_point
#include <cmath> // For std::ceil
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
//文字配列の二次元配列みたいなやつを回転させる。
vector<string> rotate90(const vector<string>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<string> rotated(m, string(n, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }
    return rotated;
}





const std::string YES = "Yes";
const std::string NO = "No";

int64_t dist2(pair<int64_t,int64_t> a, pair<int64_t,int64_t> b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n; cin >> n;
    pair<int64_t,int64_t> s, t;
    cin >> s.first >> s.second >> t.first >> t.second;
    
    vector<pair<int64_t,int64_t>> cen(n);
    vector<int64_t> rr(n);
    
    REP(i, n){
        cin >> cen[i].first >> cen[i].second >> rr[i];
    }
    
    // 円iと円jが交差・接触するか（内包はダメ）
    // (ri-rj)^2 <= dist^2 <= (ri+rj)^2
    vector<vector<int64_t>> interact(n);
    REP(i, n){
        REP3(j, i+1, n){
            int64_t d2 = dist2(cen[i], cen[j]);
            int64_t outer = (rr[i]+rr[j])*(rr[i]+rr[j]);
            int64_t inner = (rr[i]-rr[j])*(rr[i]-rr[j]);
            if(inner <= d2 && d2 <= outer){
                interact[i].push_back(j);
                interact[j].push_back(i);
            }
        }
    }
    
    // sとtがどの円の円周上にあるか
    // 点pが円iの円周上 ⟺ dist2(p, cen[i]) == rr[i]^2
    int64_t start = -1, goal = -1;
    REP(i, n){
        if(dist2(s, cen[i]) == rr[i]*rr[i]) start = i;
        if(dist2(t, cen[i]) == rr[i]*rr[i]) goal = i;
    }
    
    if(start == goal){  // s==t含む、または同じ円上
        cout << YES << "\n";
        return 0;
    }
    
    // BFS
    vector<bool> visited(n, false);
    queue<int64_t> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int64_t cur = q.front(); q.pop();
        if(cur == goal){
            cout << YES << "\n";
            return 0;
        }
        for(auto nxt : interact[cur]){
            if(!visited[nxt]){
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
    cout << NO << "\n";
    return 0;
}