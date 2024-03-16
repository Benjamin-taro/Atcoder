#!/usr/bin/env python3
# from typing import *


# def solve(S: str) -> Any:
def solve(S):
    temp = []
    for index, l in enumerate(S):
        if l == "|":
            temp.append(index)  # 正しくインデックスを格納
    # "|"が見つからなかった場合や1つしかない場合のエラーハンドリングを追加するとより堅牢になります。
    # 以下は、2つの"|"が正しく見つかった場合のみを処理する例です。
    if len(temp) >= 2:
        ans = S[:temp[0]] + S[temp[1]+1:]
    else:
        ans = S  # "|"が不足している場合は、入力された文字列をそのまま返します。
    return ans

def main():
    S = input()
    ans = solve(S)
    print(ans)

if __name__ == '__main__':
    main()
