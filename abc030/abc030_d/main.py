#!/usr/bin/env python3
# from typing import *


# def solve(a: int, b: int, c: str, d: List[int]) -> int:
def solve(a, b, c, d):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    import sys
    tokens = iter(sys.stdin.read().split())
    a = int(next(tokens))
    b = int(next(tokens))
    d = [None for _ in range(a)]
    c = next(tokens)
    for i in range(a):
        d[i] = int(next(tokens))
    assert next(tokens, None) is None
    a1 = solve(a, b, c, d)
    print(a1)


if __name__ == '__main__':
    main()
