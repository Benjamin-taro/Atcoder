#!/usr/bin/env python3
# from typing import *


# def solve(N: int, P: List[int], Q: List[int]) -> List[str]:
def solve(N, P, Q):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    import sys
    tokens = iter(sys.stdin.read().split())
    N = int(next(tokens))
    P = [None for _ in range(N)]
    Q = [None for _ in range(N)]
    for i in range(N):
        P[i] = int(next(tokens))
    for i in range(N):
        Q[i] = int(next(tokens))
    assert next(tokens, None) is None
    ans = solve(N, P, Q)
    print(*[ans[i] for i in range(N)])


if __name__ == '__main__':
    main()
