#!/usr/bin/env python3
# from typing import *

MOD = 998244353


# def solve(N: int, M: int, A: List[int]) -> int:
def solve(N, M, A):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    import sys
    tokens = iter(sys.stdin.read().split())
    N = int(next(tokens))
    M = int(next(tokens))
    A = [None for _ in range(N)]
    for i in range(N):
        A[i] = int(next(tokens))
    assert next(tokens, None) is None
    a = solve(N, M, A)
    print(a)


if __name__ == '__main__':
    main()