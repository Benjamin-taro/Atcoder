#!/usr/bin/env python3
# from typing import *


# def solve(N: int, H: List[int], S: List[int]) -> int:
def solve(N, H, S):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    N = int(input())
    H = [None for _ in range(N)]
    S = [None for _ in range(N)]
    for i in range(N):
        H[i], S[i] = map(int, input().split())
    a = solve(N, H, S)
    print(a)


if __name__ == '__main__':
    main()