#!/usr/bin/env python3
# from typing import *


# def solve(N: int, Q: int, x: List[int]) -> List[str]:
def solve(N, Q, x):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    import sys
    tokens = iter(sys.stdin.read().split())
    N = int(next(tokens))
    Q = int(next(tokens))
    x = [None for _ in range(Q)]
    for i in range(Q):
        x[i] = int(next(tokens))
    assert next(tokens, None) is None
    A = solve(N, Q, x)
    print(*[A[i] for i in range(N)])


if __name__ == '__main__':
    main()
