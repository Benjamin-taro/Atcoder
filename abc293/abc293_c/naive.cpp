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

int main(void)
{
  int h, w;
  int a[11][11];
  
  cin >> h >> w;
  for(int y = 1; y <= h; y++) for(int x = 1; x <= w; x++) cin >> a[x][y];
  
  int p[20], l = h+w-2, ans = 0;
  for(int i = 1; i <= l; i++){
    if(i > w-1) p[i] = 1;
    else p[i] = 0;
  }
  
  do{
    int x = 1, y = 1;
    set<int> S; S.insert(a[1][1]);
    for(int i = 1; i <= l; i++){
      if(p[i]) y++;
      else x++;
      S.insert(a[x][y]);
    }
    if(S.size() == l+1) ans++;
  }while(next_permutation(p+1, p+l+1));
  
  cout << ans << endl;
  return 0;
}
