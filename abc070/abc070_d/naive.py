#!/usr/bin/env python3
# from typing import *


# def solve(N: int, a: List[int], b: List[int], c: List[int], Q: int, K: int, x: List[int], y: List[int]) -> List[str]:
def solve(N, a, b, c, Q, K, x, y):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    N = int(input())
    a = [None for _ in range(N - 1)]
    b = [None for _ in range(N - 1)]
    c = [None for _ in range(N - 1)]
    for i in range(N - 1):
        a[i], b[i], c[i] = map(int, input().split())
    Q, K = map(int, input().split())
    x = [None for _ in range(Q)]
    y = [None for _ in range(Q)]
    for i in range(Q):
        x[i], y[i] = map(int, input().split())
    d = solve(N, a, b, c, Q, K, x, y)
    for i in range(Q):
        print(d[i])


if __name__ == '__main__':
    main()