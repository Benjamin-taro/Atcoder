def compute_cumulative_sum(S):
    """'o'の累積和と'x'の存在を記録する累積和を計算する"""
    H = len(S)
    W = len(S[0])
    cum_sum = [[0] * (W + 1) for _ in range(H)]
    for i in range(H):
        for j in range(1, W + 1):
            cum_sum[i][j] = cum_sum[i][j-1] + (1 if S[i][j-1] == 'o' else 0)
    return cum_sum

def min_additions_for_interval(cum_sum, K, length):
    """指定された区間内で追加する必要がある最小の'o'の数を計算する"""
    min_additions = 10**18
    for i in range(len(cum_sum)):
        for j in range(length - K + 1):
            o_count = cum_sum[i][j+K] - cum_sum[i][j]
            if K - o_count < min_additions:
                min_additions = K - o_count
    return min_additions

def solve(H, W, K, S):
    # 'o'の累積和を計算
    cum_sum = compute_cumulative_sum(S)
    
    # 行に対する最小追加数を計算
    output = min_additions_for_interval(cum_sum, K, W)
    
    # Sを転置して列に対する計算を行う
    S_transposed = ["".join(row) for row in zip(*S)]
    cum_sum_transposed = compute_cumulative_sum(S_transposed)
    
    # 列に対する最小追加数を計算
    output_transposed = min_additions_for_interval(cum_sum_transposed, K, H)
    
    # 最小値を取得
    output = min(output, output_transposed)
    
    return -1 if output == 10**18 else output

def main():
    # 入力を受け取る
    H, W, K = map(int, input().split())
    S = ["#" + input() for _ in range(H)]  # 添字を1ベースで扱うための処理

    ans = 1e9  # 答えを格納する変数を十分大きな値で初期化

    # 行に対する処理
    for y in range(H):
        X, D = [0] * (W + 1), [0] * (W + 1)  # 累積和を格納するリスト
        for i in range(1, W + 1):
            X[i] = X[i-1] + (S[y][i] == 'x')
            D[i] = D[i-1] + (S[y][i] == '.')
        for i in range(1, W - K + 2):
            if X[i+K-1] - X[i-1] == 0:
                ans = min(ans, D[i+K-1] - D[i-1])

    # 列に対する処理
    for x in range(W):
        X, D = [0] * (H + 1), [0] * (H + 1)  # 累積和を格納するリスト
        for i in range(1, H + 1):
            X[i] = X[i-1] + (S[i-1][x+1] == 'x')  # Sは0ベースでアクセス
            D[i] = D[i-1] + (S[i-1][x+1] == '.')
        for i in range(1, H - K + 2):
            if X[i+K-1] - X[i-1] == 0:
                ans = min(ans, D[i+K-1] - D[i-1])

    # 条件を満たす解が存在しない場合
    if ans > K:
        ans = -1

    print(ans)

if __name__ == "__main__":
    main()

