#!/usr/bin/env python3
# from typing import *

YES = 'Yes'
NO = 'No'


# def solve(S: List[int]) -> str:
def solve(S):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    S = [None for _ in range(8)]
    import sys
    tokens = iter(sys.stdin.read().split())
    for i in range(8):
        S[i] = int(next(tokens))
    assert next(tokens, None) is None
    a = solve(S)
    print(a)


if __name__ == '__main__':
    main()
