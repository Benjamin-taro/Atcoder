#!/usr/bin/env python3
# from typing import *

YES = 'possible'
NO = 'impossible'


# def solve(H: int, W: int, S: List[str]) -> Any:
def solve(H, W, S):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    H, W = map(int, input().split())
    S = [None for _ in range(H)]
    for i in range(H):
        S[i] = input()
    ans = solve(H, W, S)
    print(ans)  # TODO: edit here


if __name__ == '__main__':
    main()
