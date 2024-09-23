#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

// 文字列中の文字の出現回数を数える関数
map<char, int> countCharFreq(const string& str) {
    map<char, int> freq;
    for (char c : str) {
        freq[c]++;
    }
    return freq;
}

// 並び替えを許した場合の最長共通部分文字列を見つける
string findLongestCommonSubstringWithAnagram(const vector<string>& S) {
    // 最初の文字列の文字出現回数を取得
    map<char, int> commonFreq = countCharFreq(S[0]);

    // 2つ目以降の文字列に共通する最小の出現回数を求める
    for (int i = 1; i < S.size(); ++i) {
        map<char, int> currentFreq = countCharFreq(S[i]);
        // すべての文字に対して、最小の出現回数を更新
        for (auto& [char_, count] : commonFreq) {
            if (currentFreq.find(char_) != currentFreq.end()) {
                commonFreq[char_] = min(count, currentFreq[char_]);
            } else {
                commonFreq[char_] = 0;
            }
        }
    }

    // 共通している文字を出現回数に基づいて集めて最長共通部分を構築
    string result = "";
    for (auto& [char_, count] : commonFreq) {
        result += string(count, char_);  // count 回繰り返す
    }

    // 辞書順で最も早い文字列を作成するためにソート
    sort(result.begin(), result.end());

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> S(n);
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }
    
    string result = findLongestCommonSubstringWithAnagram(S);
    cout << result << endl;
    
    return 0;
}
