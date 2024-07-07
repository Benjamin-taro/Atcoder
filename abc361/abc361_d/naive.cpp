#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

// 状態を管理するための構造体
struct GameState {
    string config;
    int empty1, empty2;

    bool operator==(const GameState &other) const {
        return config == other.config;
    }

    bool operator<(const GameState &other) const {
        return config < other.config;
    }
};

// ハッシュ関数
namespace std {
    template <>
    struct hash<GameState> {
        size_t operator()(const GameState &state) const {
            return hash<string>()(state.config);
        }
    };
}

// 幅優先探索を用いて初期状態から目標状態までの最小操作回数を求める
int minMovesToReach(const GameState &initial, const GameState &target) {
    unordered_set<GameState> visited;
    queue<pair<GameState, int>> q;

    q.push({initial, 0});
    visited.insert(initial);

    while (!q.empty()) {
        GameState current = q.front().first;
        int depth = q.front().second;
        q.pop();

        // 目標状態に到達した場合
        if (current.config == target.config) {
            return depth;
        }

        // 現在の状態から次の状態を生成
        for (int i = 0; i < current.config.size(); ++i) {
            for (int j = i + 1; j < current.config.size(); ++j) {
                if (current.config[i] != 'D' && current.config[j] != 'D') {
                    GameState newState = current;

                    // 2つの石を動かす
                    swap(newState.config[newState.empty1], newState.config[i]);
                    swap(newState.config[newState.empty2], newState.config[j]);

                    newState.empty1 = i;
                    newState.empty2 = j;

                    if (visited.find(newState) == visited.end()) {
                        visited.insert(newState);
                        q.push({newState, depth + 1});
                    }

                    // 元に戻す
                    swap(newState.config[newState.empty1], newState.config[i]);
                    swap(newState.config[newState.empty2], newState.config[j]);
                }
            }
        }
    }

    return -1;  // 到達不可能な場合
}

void solve(int64_t N, const string &S, const string &T) {
    GameState initial, target;

    initial.config = S + "DD";
    target.config = T + "DD";

    // 初期状態の空の位置を取得
    initial.empty1 = initial.config.find('D');
    initial.empty2 = initial.config.find('D', initial.empty1 + 1);

    // 目標状態の空の位置を取得
    target.empty1 = target.config.find('D');
    target.empty2 = target.config.find('D', target.empty1 + 1);

    int result = minMovesToReach(initial, target);
    if (result != -1) {
        cout << "Minimum moves: " << result << endl;
    } else {
        cout << "It is not possible to reach the target configuration." << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t N;
    std::string S, T;
    std::cin >> N >> S >> T;

    solve(N, S, T);

    return 0;
}
