#!/usr/bin/env python3
# from typing import *

YES = 'POSSIBLE'
NO = 'IMPOSSIBLE'


# def solve(N: int, M: int, a: List[int], b: List[int]) -> str:
def solve(N, M, a, b):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    N, M = map(int, input().split())
    a = [None for _ in range(M)]
    b = [None for _ in range(M)]
    for i in range(M):
        a[i], b[i] = map(int, input().split())
    a1 = solve(N, M, a, b)
    print(a1)


if __name__ == '__main__':
    main()