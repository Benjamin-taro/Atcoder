#!/usr/bin/env python3
# from typing import *


# def solve(N: int, S: int, T: int, A: List[int], B: List[int], C: List[int], D: List[int]) -> float:
def solve(N, S, T, A, B, C, D):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    N, S, T = map(int, input().split())
    A = [None for _ in range(N)]
    B = [None for _ in range(N)]
    C = [None for _ in range(N)]
    D = [None for _ in range(N)]
    for i in range(N):
        A[i], B[i], C[i], D[i] = map(int, input().split())
    a = solve(N, S, T, A, B, C, D)
    print(a)


if __name__ == '__main__':
    main()
