#!/usr/bin/env python3
# from typing import *


# def solve(P: List[int]) -> str:
def solve(P):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    P = [None for _ in range(26)]
    import sys
    tokens = iter(sys.stdin.read().split())
    for i in range(26):
        P[i] = int(next(tokens))
    assert next(tokens, None) is None
    a = solve(P)
    print(a)


if __name__ == '__main__':
    main()