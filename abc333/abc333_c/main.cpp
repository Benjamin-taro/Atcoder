#include <iostream>
#include <string>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int d = 1; d <= 12; d++) {
    for(int a = d - 1; a >= 0; a--) {
      for(int b = d - a - 1; b >= 0; b--) {
        int c = d - a - b;
        if(--n == 0) {
          cout << string(a, '1') + string(b, '2') + string(c, '3') << endl;
          return 0;
        }
      }
    }
  }
}