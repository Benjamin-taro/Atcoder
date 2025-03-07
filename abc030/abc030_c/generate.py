#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    N = random.randint(1, 1000)  # TODO: edit here
    a = [None for _ in range(N)]
    M = random.randint(1, 1000)  # TODO: edit here
    b = [None for _ in range(M)]
    X = random.randint(1, 10**9)  # TODO: edit here
    Y = random.randint(1, 10**9)  # TODO: edit here
    for i in range(N):
        a[i] = random.randint(1, 10**9)  # TODO: edit here
    for i in range(M):
        b[i] = random.randint(1, 10**9)  # TODO: edit here
    print(N, M)
    print(X, Y)
    print(*[a[i] for i in range(N)])
    print(*[b[i] for i in range(M)])


if __name__ == "__main__":
    main()
