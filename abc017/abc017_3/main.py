#!/usr/bin/env python3
# from typing import *


# def solve(N: int, M: int, l: List[int], r: List[int], s: List[int]) -> int:
def solve(N, M, l, r, s):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    N, M = map(int, input().split())
    l = [None for _ in range(N)]
    r = [None for _ in range(N)]
    s = [None for _ in range(N)]
    for i in range(N):
        l[i], r[i], s[i] = map(int, input().split())
    a = solve(N, M, l, r, s)
    print(a)


if __name__ == '__main__':
    main()