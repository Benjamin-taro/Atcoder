#!/usr/bin/env python3
# from typing import *


# def solve(N: int, Q: int, H: List[str], T: List[int]) -> int:
def solve(N, Q, H, T):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    import sys
    tokens = iter(sys.stdin.read().split())
    N = int(next(tokens))
    Q = int(next(tokens))
    H = [None for _ in range(Q)]
    T = [None for _ in range(Q)]
    for i in range(Q):
        H[i] = next(tokens)
        T[i] = int(next(tokens))
    assert next(tokens, None) is None
    a = solve(N, Q, H, T)
    print(a)


if __name__ == '__main__':
    main()