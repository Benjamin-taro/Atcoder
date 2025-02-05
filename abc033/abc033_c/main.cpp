#include <iostream>
#include <string>

int64_t solve(std::string S) {
    S += '+'; // ダミーの演算子を追加して最後のセグメントを処理
    int64_t ans = 0;
    bool containsMultiplication = false;
    bool containsZero = false;
    int64_t countDigits = 0;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '+' || S[i] == '*') {
            if (S[i] == '*') {
                containsMultiplication = true;
            }
            if (S[i] == '+') {
                // すでに 0 を含む場合、何も変更しなくてもこの部分式は 0 になる
                if (!containsZero) {
                    // 乗算を含む場合は 1つの数字を 0 にすれば良い
                    if (containsMultiplication) {
                        ans++;
                    }
                    // 乗算を含まない場合はすべての数字を 0 にする必要がある
                    else if (countDigits > 0) {
                        ans += countDigits;
                    }
                }
                // 次のセグメントのためのリセット
                containsMultiplication = false;
                containsZero = false;
                countDigits = 0;
            }
        } else {
            countDigits++;
            if (S[i] == '0') {
                containsZero = true;
            }
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string S;
    std::cin >> S;
    auto ans = solve(S);
    std::cout << ans << '\n';
    return 0;
}
