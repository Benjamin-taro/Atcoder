#!/usr/bin/env python3
# from typing import *


def solve(N, P, Q):
    # ゼッケン番号から人のインデックスを特定する辞書を作成
    bib_to_person = [0] * N
    for i in range(N):
        bib_to_person[Q[i]] = i  # Q[i] 番のゼッケンを着けているのは i 番の人

    result = [0] * N
    for i in range(N):
        person_wearing_bib_i = bib_to_person[i]  # i 番のゼッケンを着けている人のインデックス
        person_watching = P[person_wearing_bib_i]  # その人を見つめている人
        result[i] = Q[person_watching] + 1  # その人が着けているゼッケン番号を出力（1-indexed に戻す）
    
    return result

# メイン関数はそのままでOK
def main():
    import sys
    tokens = iter(sys.stdin.read().split())
    N = int(next(tokens))
    P = [int(next(tokens)) - 1 for _ in range(N)]
    Q = [int(next(tokens)) - 1 for _ in range(N)]
    assert next(tokens, None) is None
    ans = solve(N, P, Q)
    print(*ans)

if __name__ == '__main__':
    main()
