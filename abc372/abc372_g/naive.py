#!/usr/bin/env python3
# from typing import *


# def solve(a: int, b: List[int], c: List[List[int]], d: List[List[int]], e: List[List[int]]) -> List[str]:
def solve(a, b, c, d, e):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    a = int(input())
    b = [None for _ in range(a)]
    c = [[None for _ in range(b_i)] for _ in range(a)]
    d = [[None for _ in range(b_i)] for _ in range(a)]
    e = [[None for _ in range(b_i)] for _ in range(a)]
    for i in range(a):
        b[i] = int(input())
        for j in range(b_i):
            c[i][j], d[i][j], e[i][j] = map(int, input().split())
    f = solve(a, b, c, d, e)
    for i in range(a):
        print(f[i])


if __name__ == '__main__':
    main()