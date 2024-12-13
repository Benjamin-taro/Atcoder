#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

// エラトステネスの篩で素数リストを生成
vector<int64_t> sieve(int64_t limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int64_t i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (int64_t j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int64_t> primes;
    for (int64_t i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// 条件を満たす平方数を求める
vector<int64_t> find_special_squares(int64_t N) {
    int64_t limit = sqrt(N); // sqrt(N)までの素数が必要
    vector<int64_t> primes = sieve(limit);
    set<int64_t> results;

    // 2つの素数の積の平方を生成
    for (size_t i = 0; i < primes.size(); ++i) {
        for (size_t j = i + 1; j < primes.size(); ++j) { // 異なる素数のみ
            if (primes[i] > sqrt(N) / primes[j]) break; // オーバーフロー防止
            int64_t product = primes[i] * primes[j];
            int64_t square = product * product;
            if (square > N) break; // Nを超えたら終了

            // デバッグ用にログを出力
            // cout << "Primes: " << primes[i] << ", " << primes[j]
            //      << " -> Square: " << square << endl;

            results.insert(square);
        }
    }

    // 結果をベクターに変換
    return vector<int64_t>(results.begin(), results.end());
}

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> special_squares = find_special_squares(N);

    cout << special_squares.size() << endl;
    return 0;
}
