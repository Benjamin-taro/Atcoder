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



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, X;
    cin >> N >> X;
    string S;
    cin >> S;

    // 1. X の根からのパス (path) を求める
    //    子 -> 親 の逆順で L/R を集めておき、最後に反転
    //    例: X=13 -> (13 odd -> 'R'), X=6 -> (6 even -> 'L'), X=3 -> (3 odd -> 'R'), X=1
    //         逆順 "RLR" を反転すると "RLR"(同じだが実際は逆かもしれない) という具合
    string pathRev;
    long long cur = X;
    while(cur > 1){
        if(cur % 2 == 0){
            pathRev.push_back('L');
        } else {
            pathRev.push_back('R');
        }
        cur /= 2;
    }
    // root(=1)まで来たら終了
    // 逆順を反転して根->X のパスにする
    reverse(pathRev.begin(), pathRev.end());

    // いま pathRev が根(1)から X への道のり
    // 以下ではこのパスを「path」として使う:
    // (メモリ節約のため、そのまま pathRev を流用してもOKだが分かりやすさ優先)
    string path = pathRev;

    // 2. S の指示を順に処理
    for(char c : S){
        if(c == 'U'){
            if(!path.empty()){
                // 親へ移動 (末尾を削除)
                path.pop_back();
            }
            // path が空なら今は根なので何もしない
        } else if(c == 'L'){
            // 左へ
            path.push_back('L');
        } else { // c == 'R'
            // 右へ
            path.push_back('R');
        }
    }

    // 3. 最終的なパスから頂点番号を計算
    long long ans = 1; // 根
    for(char c : path){
        if(c == 'L'){
            ans = ans * 2;
        } else { // 'R'
            ans = ans * 2 + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
