#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

int main() {
	char a, b, c, d;
	cin >> a >> b >> c >> d;
	auto near = [](char x, char y) {
		if(x > y) swap(x, y);
		return y - x == 1 or y - x == 4;
	};
	if(near(a, b) == near(c, d))
		cout << "Yes\n";
	else
		cout << "No\n";
}