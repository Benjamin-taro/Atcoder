#!/usr/bin/env python3
# from typing import *

YES = 'Yes'
NO = 'No'


# def solve(N: str, M: str, u: List[str], v: List[str]) -> Tuple[str, List[str]]:
def solve(N, M, u, v):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    N, M = input().split()
    u = [None for _ in range(M)]
    v = [None for _ in range(M)]
    for i in range(M):
        u[i], v[i] = input().split()
    Yes, X = solve(N, M, u, v)
    print(Yes)
    print(*[X[i] for i in range(N)])


if __name__ == '__main__':
    main()
