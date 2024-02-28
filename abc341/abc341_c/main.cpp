#include <iostream>
#include <string>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

// Function to calculate the number of possible positions
int solve(int H, int W, int N, const std::string& T, const std::vector<std::string>& S) {
    int ans = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int x = j, y = i;
            bool valid = true;
            for (char k : T) {
                if (S[y][x] == '#') {
                    valid = false;
                    break;
                }
                if (k == 'U' && y > 0) {
                    y -= 1;
                } else if (k == 'D' && y < H - 1) {
                    y += 1;
                } else if (k == 'R' && x < W - 1) {
                    x += 1;
                } else if (k == 'L' && x > 0) {
                    x -= 1;
                } else {
                    valid = false;
                    break;
                }
            }
            if (valid && S[y][x] != '#') {
                ans += 1;
            }
        }
    }
    return ans;
}

// Main function to run the solve function
int main() {
    int H, W, N;
    std::cin >> H >> W >> N;
    std::string T;
    std::cin >> T;
    std::vector<std::string> S(H);
    for (int i = 0; i < H; ++i) {
        std::cin >> S[i];
    }
    int ans = solve(H, W, N, T, S);
    std::cout << ans << std::endl;
    return 0;
}
